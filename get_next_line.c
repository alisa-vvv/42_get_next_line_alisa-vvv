/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                     :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: avaliull <avaliull@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:37:21 by avaliull          #+#    #+#             */
/*   Updated: 2024/12/06 20:23:57 by avaliull       ########   odam.nl        */
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

static char	*find_nl(char **buff_str, int fd, int buff_len)
{
	char	*next_line;
	ssize_t	i;
	ssize_t	next_line_end;

	if (!next_line)
		return (NULL);
	i = 0;
	//maybe addd strchr to utils to do this, seems reasonable, could have smaller fnctions and less dumb shit
	while (i <= BUFFER_SIZE && buff_str[fd][i])
	{
		if (buff_str[fd][i] == "\n")
		{
			next_line_end = i;
			break ;
		}
		i++;
	}
	if (i == BUFFER_SIZE || buff_str[fd][i] == '\0')
		printf("here would be the bzero function");
	else
		trim_buff(buff_str, next_line_end);
	return (next_line);
}

#include <stdio.h>
char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE];
	char *const	curbuf = buffer[fd];
	int			read_return;
	char		*next_line;

	printf("checking what's inside: %s\n", buffer[fd]);
	if (buffer[fd][0] == 0)
	{
		read_return = read(fd, buffer[fd], BUFFER_SIZE);
		if (read_return <= 0)
			return (NULL);
	}
	else
	{
		printf("here would be find_nl");
		//next_line = find_nl(&buffer[fd], fd, read_return);
	}
	next_line = gnl_calloc(read_return + 1);
	int	i = 0;
	while (i < read_return)
	{
		next_line[i] = buffer[fd][i];
		i++;
	}
	//i = 0;
	//int j = 0;
	//while (i < 1024)
	//{
	//	if (buff_str[i] == NULL)
	//		printf("null check works, this is array number %d\n", i);
	//	while (buff_str[i][j] != 0)
	//	{
	//		printf("array %d has stuff: %c", i, buff_str[i][j]);
	//		j++;
	//	}
	//	i++;
	//}
	return (next_line);
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
//	return (next_line);
}
