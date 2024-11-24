/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   get_next_line.c                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: avaliull <avaliull@student.codam.nl>                       +#+       */
/*                                                    +#+                     */
/*   Created: 2024/11/24 12:37:21 by avaliull       #+#    #+#                */
/*   Updated: 2024/11/24 19:26:08 by avaliull       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*alloc_next_line(char *buff_str, size_t mem, char edge)
{
	char	*next_line;
	size_t	i;
	size_t	j;

	next_line = malloc(mem);
	if (!next_line)
		return (NULL);
	i = 0;
	while (i != edge)
	{
		next_line[i] = buff_str[i];
		i++;
	}
	next_line[i] = '\0';
	j = 0;
	while(i < BUFFER_SIZE)
	{
		buff_str[j] = buff_str[i];
		buff_str[i] = '\0';
		i++;
		j++;
	}
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	buff_str[BUFFER_SIZE + 1];
	char		*next_line;
	int		read_re;

	read_re = read(fd, buff_str, BUFFER_SIZE);
	if (read_re < 0)
		return (NULL);
	while (buff_str[i] != '\0')
	{
		if (buff[i] == '\n')
		{
			/*MALLOC I + 1 MEM, RETURN STR */
			/*MOVE THE BUFFER */
			return (next_line);
		}
		i++;
	}
	/* MALLOC I*/
	/* NULL THE BUFFER */
	return (next_line);
}
