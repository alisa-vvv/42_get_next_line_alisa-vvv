/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   get_next_line_utils.c                               :+:    :+:           */
/*                                                      +:+                   */
/*   By: avaliull <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/26 15:27:38 by avaliull       #+#    #+#                */
/*   Updated: 2024/11/29 15:55:34 by avaliull       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	buff_zero(char *buff_str)
{
	size_t	i;

	i = 0;
	while (buff_str[i])
	{
		buff_str[i] = '\0';
		i++;
	}
	free(buff_str);
	buff_str = NULL;
}

ssize_t	gnl_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*alloc_buff(char *buff_str, char *next_read)
{
	size_t	i;
	size_t	read_len;

	read_len = gnl_strlen(next_read);
	i = 0;
	buff_str = malloc(read_len + 1);
	if (!buff_str)
		return (NULL);
	while (i < read_len + 1)
	{
		buff_str[i] = *next_read++;
		i++;
	}
	return (buff_str);
}

char	*gnl_cat(char *buff_str, char *next_read)
{
	char	*new_buff;
	size_t	buff_len;
	size_t	read_len;
	size_t	i;

	i = 0;
	read_len = gnl_strlen(next_read);
	buff_len = gnl_strlen(buff_str);
	new_buff = malloc(read_len + buff_len + 1);
	if (!new_buff)
		return (NULL);
	while (i < buff_len)
	{
		new_buff[i] = buff_str[i];
		i++;
	}
	while (i < buff_len + read_len + 1)
	{
		new_buff[i] = *next_read++;
		i++;
	}
	free(buff_str);
	return (new_buff);
}

void	trim_buff(char *buff_str, ssize_t next_line_end)
{
	ssize_t	i;
	ssize_t	buff_len;
	ssize_t	new_buff_len;
//	char	*new_buff;

	printf("untrimmed buff: %s\n", buff_str);
	i = 0;
	buff_len = gnl_strlen(buff_str);
	if (buff_len == next_line_end + 1)
		return ;
	if (!buff_str)
		return ;
	new_buff_len = buff_len - next_line_end;
	//printf("checking buff_len%zu\n", buff_len);
	//printf("checking new_buff_len%zu\n", new_buff_len);
	//new_buff = malloc(new_buff_len + 1);
	//if (!new_buff)
	//	return (NULL);
	//next_line_end++;
	//while (i < buff_len)
	//{
	//	new_buff[i] = buff_str[next_line_end];
	//	i++;
	//	next_line_end++;
	//}
	//printf("new_buff: %s\n", new_buff);
	//free(buff_str);
	//return (new_buff);
	next_line_end++;
	while (i <= new_buff_len)
	{
		buff_str[i] = buff_str[next_line_end + i];
		i++;
	}
	while (next_line_end)
	{
		buff_str[buff_len] = '\0';
		next_line_end--;
		buff_len--;
	}
	printf("trimmed buff: %s\n", buff_str);
}
