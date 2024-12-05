/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                     :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: avaliull <avaliull@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:37:21 by avaliull          #+#    #+#             */
/*   Updated: 2024/12/05 19:00:36 by avaliull       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	gnl_cat(char **buff_str, char *next_read, int read_re_val)
{
	char	*new_buff;
	size_t	buff_len;
	size_t	i;

	i = 0;
	buff_len = gnl_strlen(*buff_str);
	new_buff = gnl_calloc(read_re_val + buff_len + 1);
	if (!new_buff)
	{
		buff_zero(buff_str);
		return ;
	}
	while (i < buff_len)
	{
		new_buff[i] = (*buff_str)[i];
		i++;
	}
	while (i < buff_len + read_re_val)
	{
		new_buff[i] = *next_read++;
		i++;
	}
	free(*buff_str);
	*buff_str = new_buff;
}

static int	rec_read(char **buff_str, int fd, int next_line_end)
{
	char	next_read[BUFFER_SIZE + 1];
	int		read_re_val;
	int		i;

	read_re_val = read(fd, next_read, BUFFER_SIZE);
	if (read_re_val == 0)
		return (next_line_end);
	if (read_re_val == -1)
		return (-1);
	gnl_cat(buff_str, next_read, read_re_val);
	if (!(*buff_str))
		return (-1);
	i = 0;
	while ((*buff_str)[i] != '\0')
	{
		if ((*buff_str)[i] == '\n')
			return (i);
		i++;
	}
	next_line_end = gnl_strlen(*buff_str) - 1;
	if ((*buff_str)[i] == '\0')
		next_line_end = rec_read(buff_str, fd, next_line_end);
	return (next_line_end);
}

static char	*alloc_nl(char **buff_str, ssize_t *next_line_end, int fd)
{
	char	*next_line;

	while ((*buff_str)[*next_line_end] != '\0')
	{
		if ((*buff_str)[*next_line_end] == '\n')
			break ;
		(*next_line_end)++;
	}
	if ((*buff_str)[*next_line_end] == '\0')
	{
		*next_line_end = rec_read(buff_str, fd, *next_line_end);
		if (*next_line_end == -1)
			return (NULL);
	}
	if (*next_line_end > 1)
	{
		if ((*buff_str)[*next_line_end] == '\0')
			next_line = gnl_calloc(*next_line_end + 1);
		else
			next_line = gnl_calloc(*next_line_end + 2);
	}
	else
		next_line = gnl_calloc(2);
	return (next_line);
}

static char	*find_nl(char **buff_str, int fd)
{
	char	*next_line;
	ssize_t	i;
	ssize_t	next_line_end;

	next_line_end = 0;
	next_line = alloc_nl(buff_str, &next_line_end, fd);
	if (!next_line)
		return (NULL);
	i = 0;
	while (i <= next_line_end && (*buff_str)[i])
	{
		next_line[i] = (*buff_str)[i];
		i++;
	}
	if (i == gnl_strlen(*buff_str))
		buff_zero(buff_str);
	else if (*buff_str)
		trim_buff(buff_str, next_line_end);
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*buff_str;
	char		next_read[BUFFER_SIZE + 1];
	int			read_re_val;
	char		*next_line;

	read_re_val = read(fd, next_read, BUFFER_SIZE);
	if (read_re_val == -1 && buff_str)
	{
		buff_zero(&buff_str);
		return (NULL);
	}
	if (read_re_val <= 0 && !buff_str)
		return (NULL);
	if (read_re_val > 0 && !buff_str)
		buff_str = alloc_buff(buff_str, next_read, read_re_val);
	else
		gnl_cat(&buff_str, next_read, read_re_val);
	if (!buff_str)
		return (NULL);
	next_line = find_nl(&buff_str, fd);
	if (!next_line)
		buff_zero(&buff_str);
	return (next_line);
}
