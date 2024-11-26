/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   get_next_line.c                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: avaliull <avaliull@student.codam.nl>                       +#+       */
/*                                                    +#+                     */
/*   Created: 2024/11/24 12:37:21 by avaliull       #+#    #+#                */
/*   Updated: 2024/11/26 15:29:04 by avaliull       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


void	buffer_saver(char *buff_str, size_t i)
{
	size_t	j;

	j = 0;
	while (i < BUFFER_SIZE)
	{
		buff_str[j] = buff_str[i];
		buff_str[i] = '\0';
		i++;
		j++;
	}
	printf("SAVED BUFFER: %s\n", buff_str);
}

char	*file_reader(char *buff_str, int fd)
{
	int		read_re;
	size_t		i;

	i = 0;
	read_re = read(fd, buff_str, BUFFER_SIZE);
	if (read_re <= 0)
		return (NULL);
	while (buff_str[i] != '\0')
	{	
		if (buff_str[i] == '\n')
			return (alloc_next_line(buff_str, i + 1, i, fd));
		i++;
	}
	return (NULL);
}

char	*alloc_next_line(char *buff_str, size_t mem, size_t edge, int fd)
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
	j = 0;
	if (i < BUFFER_SIZE - 1)
		buffer_saver(buff_str, i);
	else
		buff_zero(buff_str);
	fd += 3;
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*buff_str;
	char		new_read[BUFFER_SIZE + 1];
	char		*next_line;
	size_t		i;

	printf("checking buffer: %s\n", buff_str);
	if (!*buff_str)
	{
		next_line = file_reader(new_read, fd);
		return (next_line);
	}
	else
	{
		next_line = malloc(gnl_strlen(buff_str) + 1);
		printf("123");
		if (!next_line)
			return (NULL);
		i = 0;
		while (buff_str[i])
		{
			next_line[i] = buff_str[i];
			i++;
		}
		buff_zero(buff_str);
		next_line = concatter(next_line, file_reader(buff_str, fd));	
		return (next_line);
	}
	/*SHOULD BE A FUNC THAT SAVES THE BUFFER AND READS NEXT LINE*/
	/* THEN IT CALLS THE FUNC THAT CONCATENATES EXISITNG STRINGS */
	return (NULL);
}
