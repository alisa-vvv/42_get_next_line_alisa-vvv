/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   get_next_line.c                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: avaliull <avaliull@student.codam.nl>                       +#+       */
/*                                                    +#+                     */
/*   Created: 2024/11/24 12:37:21 by avaliull       #+#    #+#                */
/*   Updated: 2024/11/29 12:59:01 by avaliull       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*find_next_line(char *buff_str, ssize_t *next_line_end)
{
	char	*next_line;
	ssize_t	i;

	while (buff_str[*next_line_end] != '\0')
	{
		if (buff_str[*next_line_end] == '\n')
			break ;
		(*next_line_end)++;
	}
	next_line = malloc(*next_line_end + 2);
	if (!next_line)
		return (NULL);
	i = 0;
	while (i <= *next_line_end)
	{
		next_line[i] = buff_str[i];
		i++;
	}
	if (buff_str[*next_line_end + i] == '\0')
		buff_zero(buff_str);
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*buff_str;
	char		next_read[BUFFER_SIZE + 1];
	int		read_re_val;
	ssize_t		next_line_end;
	char		*next_line;

	read_re_val = read(fd, next_read, BUFFER_SIZE);
	if (read_re_val > 0 && !buff_str)
	{
		buff_str = alloc_buff(buff_str, next_read);
	}
	else if (read_re_val <= 0 && !buff_str)
	{
		return (NULL);
	}
	else if (*next_read && buff_str)
	{
		buff_str = gnl_cat(buff_str, next_read);
	}
	if (!buff_str)
		return (NULL);
	next_line_end = 0;
	next_line = find_next_line(buff_str, &next_line_end);
	if (!next_line)
		return (NULL);
	printf("what?");
	if (read_re_val >= 0)
	{
		buff_str = trim_buff(buff_str, next_line_end);
		//need to add alloc failure chek
	}
	return (next_line);
}
