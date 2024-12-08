/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                     :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: avaliull <avaliull@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:37:21 by avaliull          #+#    #+#             */
/*   Updated: 2024/12/08 19:53:57 by avaliull       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//static void	gnl_cat(char **buff_str, char *next_read, int read_re_val)
//{
//	char	*new_buff;
//	size_t	buff_len;
//	size_t	i;
//
//	i = 0;
//	buff_len = gnl_strlen(*buff_str);
//	new_buff = gnl_calloc(read_re_val + buff_len + 1);
//	if (!new_buff)
//	{
//		buff_zero(buff_str);
//		return ;
//	}
//	while (i < buff_len)
//	{
//		new_buff[i] = (*buff_str)[i];
//		i++;
//	}
//	while (i < buff_len + read_re_val)
//	{
//		new_buff[i] = *next_read++;
//		i++;
//	}
//	free(*buff_str);
//	*buff_str = new_buff;
//}
//
//static int	rec_read(char **buff_str, int fd, int next_line_end)
//{
//	char	next_read[BUFFER_SIZE + 1];
//	int		read_re_val;
//	int		i;
//
//	read_re_val = read(fd, next_read, BUFFER_SIZE);
//	if (read_re_val == 0)
//		return (next_line_end);
//	if (read_re_val == -1)
//		return (-1);
//	gnl_cat(buff_str, next_read, read_re_val);
//	if (!(*buff_str))
//		return (-1);
//	i = 0;
//	while ((*buff_str)[i] != '\0')
//	{
//		if ((*buff_str)[i] == '\n')
//			return (i);
//		i++;
//	}
//	next_line_end = gnl_strlen(*buff_str) - 1;
//	if ((*buff_str)[i] == '\0')
//		next_line_end = rec_read(buff_str, fd, next_line_end);
//	return (next_line_end);
//}
//
//static char	*alloc_nl(char **buff_str, ssize_t *next_line_end, int fd)
//{
//	char	*next_line;
//
//	while ((*buff_str)[*next_line_end] != '\0')
//	{
//		if ((*buff_str)[*next_line_end] == '\n')
//			break ;
//		(*next_line_end)++;
//	}
//	if ((*buff_str)[*next_line_end] == '\0')
//	{
//		*next_line_end = rec_read(buff_str, fd, *next_line_end);
//		if (*next_line_end == -1)
//			return (NULL);
//	}
//	if (*next_line_end > 1)
//	{
//		if ((*buff_str)[*next_line_end] == '\0')
//			next_line = gnl_calloc(*next_line_end + 1);
//		else
//			next_line = gnl_calloc(*next_line_end + 2);
//	}
//	else
//		next_line = gnl_calloc(2);
//	return (next_line);
//}

void	gnl_bzero(char **mem, ssize_t size)
{
	while (--size)
		(*mem)[size] == '\0';
}

void	set_str(const char *src, char *dest, ssize_t size)
{
	dest[size] = '\0';
	while (--size >= 0)
		dest[size] = src[size];
}

ssize_t	find_nl_index(const char *buffer, int read_len)
{
	int	nl_index;

	nl_index = 0;
	while (nl_index < read_len)
	{
		if (buffer[nl_index] == "\n")
			return (nl_index);
		nl_index++;
	}
	return (nl_index);
}

static char	*rec_read(char **buff, int fd, char *next_line, ssize_t *size)
{
	int	read_return;
	char	*new_next_line;
	int	nl_index;

	read_return = read(fd, *buffer, BUFFER_SIZE);
	if (read_return == -1)
	{
		gnl_bzero(buff, BUFFER_SIZE);
		return (NULL);
	}
	if (read_return == 0)
	{
		gnl_bzero(buff, BUFFER_SIZE);
		return (next_line);
	}
	nl_index = find_nl_index(*buff, read_return);
	new_next_line = find_nl(buffer, fd, read_len);
	free(next_line);
	return (new_next_line);
}

static char	*find_nl(char **buffer, int fd, int read_len)
{
	char	*next_line;
	int	nl_index;

	//maybe addd strchr to utils to do this, seems reasonable, could have smaller fnctions and less dumb shit
	nl_index = find_nl_index(*buffer, read_len);
	next_line = malloc(nl_index + 1 + (nl_index != read_len));
	if (!next_line)
		return (NULL);
	if (nl_index == read_len)
	{
		set_str(*buffer, next_line, read_len);
		next_line = rec_read(buffer, fd, next_line);
		return (next_line);
	}
	set_str(*buffer, next_line, nl_index + 1);
	trim_buff(buff_str, next_line_end);
	return (next_line);
}

#include <stdio.h>
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	int			read_return;
	char		*next_line;

	printf("checking what's inside: %s\n", buffer[fd]);
	if (buffer[0] == 0)
	{
		read_return = read(fd, buffer, BUFFER_SIZE);
		if (read_return <= 0)
			return (NULL);
	}
	next_line = find_nl(&buffer, fd, read_return);
//	if (read_re_val == -1 && buff_str)
//	{
//		buff_zero(&buff_str);
//		return (NULL);
//	}
//	if (read_re_val <= 0 && !buff_str)
//		return (NULL);
//	if (read_re_val > 0 && !buff_str)
//		buff_str = alloc_buff(buff_str, next_read, read_re_val);
//	else
//		gnl_cat(&buff_str, next_read, read_re_val);
//	if (!buff_str)
//		return (NULL);
//	next_line = find_nl(&buff_str, fd);
//	if (!next_line)
//		buff_zero(&buff_str);
	return (next_line);
}
