/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                     :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: avaliull <avaliull@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:37:21 by avaliull          #+#    #+#             */
/*   Updated: 2024/12/10 15:41:11 by avaliull       ########   odam.nl        */
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
		(*mem)[size] = '\0';
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
		if (buffer[nl_index] == '\n')
			return (nl_index);
		nl_index++;
	}
	return (nl_index);
}

char	*gnl_str_join(char *str1, char *str2, ssize_t len_1, ssize_t len_2)
{
	ssize_t	new_len;
	char	*new_str;

	new_len = len_1 + len_2;
	new_str = malloc(new_len + 1);
	if (!new_str)
		return (NULL);	
	set_str(str1, new_str, len_1);
	set_str(str2, new_str + len_1, len_2);
	return (new_str);
}

static char	*read_loop(char **buffer, int fd, char *next_line, ssize_t len)
{
	char	*tmp_next_line;
	int	read_return;
	int	nl_index;
	int	keep_reading;

	keep_reading = 1;
	while (keep_reading == 1)
	{
		read_return = read(fd, *buffer, BUFFER_SIZE);
		if (read_return < 0)
		{
			free(next_line);
			return (NULL);
		}
		if (read_return == 0)
		{
			gnl_bzero(buffer, BUFFER_SIZE);
			return (next_line);
		}
		nl_index = find_nl_index(*buffer, read_return);
		if (nl_index < read_return)
		{
			tmp_next_line = gnl_str_join(next_line, *buffer, len, nl_index);
			keep_reading = 0;
		}
		else
			tmp_next_line = gnl_str_join(next_line, *buffer, len, read_return - 1);
		if (!tmp_next_line)
			keep_reading = 0;
		free(next_line);
		next_line = tmp_next_line;
		len += read_return;
	}
	trim_buff(buffer, nl_index);
	return (next_line);
}

static char	*find_nl(char **buffer, int fd, int buff_len)
{
	char	*next_line;
	int	nl_index;

	nl_index = find_nl_index(*buffer, buff_len);
	if (nl_index == buff_len)
		next_line = malloc(nl_index);	
	else
		next_line = malloc(nl_index + 1);
	if (!next_line)
		return (NULL);
	if (nl_index == buff_len)
	{
		set_str(*buffer, next_line, nl_index);
		next_line = read_loop(buffer, fd, next_line, buff_len);
		return (next_line);
	}
	set_str(*buffer, next_line, nl_index + 1);
	//this ocndtionfjg craxy
	if (buff_len < BUFFER_SIZE && nl_index > buff_len)
		gnl_bzero(buffer, BUFFER_SIZE);
	else
		trim_buff(buffer, nl_index);
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
	printf("buff_len: %d\n", buff_len);
	buffer_ptr = &buffer[0];
	next_line = find_nl(&buffer_ptr, fd, buff_len);
	return (next_line);
}
