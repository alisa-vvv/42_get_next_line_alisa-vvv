/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                     :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: avaliull <avaliull@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:37:21 by avaliull          #+#    #+#             */
/*   Updated: 2024/12/11 19:56:39 by avaliull       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static ssize_t	find_nl_index(const char *buffer, int read_len)
{
	int	nl_index;

	nl_index = 0;
	while (nl_index < read_len)
	{
		if (buffer[nl_index] == '\n')
			return (nl_index);
		nl_index++;
	}
	return (nl_index);
}

static char	*eof_or_error(char **buffer, int read_return, char *next_line)
{
	gnl_bzero(buffer, BUFFER_SIZE);
	if (read_return == 0)
		return (next_line);
	free(next_line);
	return (NULL);
}

static char	*read_loop(char **buffer, int fd, char *next_line, ssize_t len)
{
	int	read_return;
	int	nl_index;

	while (1)
	{
		read_return = read(fd, *buffer, BUFFER_SIZE);
		if (read_return <= 0)
			return (eof_or_error(buffer, read_return, next_line));
		nl_index = find_nl_index(*buffer, read_return);
		if (nl_index < read_return)
		{
			next_line = gnl_str_join(next_line, *buffer, len, nl_index + 1);
			break ;
		}
		next_line = gnl_str_join(next_line, *buffer, len, read_return);
		if (!next_line)
			return (NULL);
		len += read_return;
	}
	if (nl_index == read_return - 1 && read_return < BUFFER_SIZE)
		gnl_bzero(buffer, BUFFER_SIZE);
	else
		trim_buff(buffer, nl_index, read_return);
	return (next_line);
}

static char	*find_nl(char **buffer, int fd, int buff_len)
{
	char	*next_line;
	int	nl_index;

	nl_index = find_nl_index(*buffer, buff_len);
	if (nl_index == buff_len)
		next_line = malloc(nl_index + 1);
	else
		next_line = malloc(nl_index + 2);
	if (!next_line)
		return (NULL);
	if (nl_index == buff_len)
	{
		set_str(*buffer, next_line, buff_len);
		next_line = read_loop(buffer, fd, next_line, buff_len);
		return (next_line);
	}
	set_str(*buffer, next_line, nl_index + 1);
	if (nl_index == buff_len - 1 && buff_len < BUFFER_SIZE)
		gnl_bzero(buffer, BUFFER_SIZE);
	else
		trim_buff(buffer, nl_index, buff_len);
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*buffer_ptr;
	char		*next_line;
	int		buff_len;

	buff_len = 0;
	if (buffer[0] == '\0')
	{
		buff_len = read(fd, buffer, BUFFER_SIZE);
		if (buff_len <= 0)
			return (NULL);
	}
	if (!buff_len)
	{
		while (buffer[buff_len] && buff_len < BUFFER_SIZE)
		{
			if (buffer[buff_len] == '\0')
				break ;
			buff_len++;
		}
	}
	buffer_ptr = &buffer[0];
	next_line = find_nl(&buffer_ptr, fd, buff_len);
	return (next_line);
}
