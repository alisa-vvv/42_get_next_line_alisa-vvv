/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   get_next_line_utils.c                               :+:    :+:           */
/*                                                      +:+                   */
/*   By: avaliull <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/26 15:27:38 by avaliull       #+#    #+#                */
/*   Updated: 2024/12/01 18:13:14 by avaliull       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*buff_zero(char *buff_str)
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
	return (buff_str);
}

int	gnl_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*alloc_buff(char *buff_str, char *next_read, int read_re_val)
{
	int	i;

	i = 0;
	buff_str = gnl_calloc(read_re_val + 1);
	if (!buff_str)
		return (NULL);
	while (i < read_re_val)
	{
		buff_str[i] = *next_read++;
		i++;
	}
	return (buff_str);
}

void	gnl_cat(char **buff_str, char *next_read, int read_re_val)
{
	char	*new_buff;
	int	buff_len;
	int	i;

	i = 0;
	buff_len = gnl_strlen(*buff_str);
	new_buff = gnl_calloc(read_re_val + buff_len + 1);
	if (!new_buff)
		return (NULL);
	while (i < buff_len)
	{
		new_buff[i] = buff_str[i];
		i++;
	}
	while (i < buff_len + read_re_val)
	{
		new_buff[i] = *next_read++;
		i++;
	}
	new_buff[i] = '\0';
	free(*buff_str);
	*buff_str = new_buff;
}

void	trim_buff(char *buff_str, int next_line_end)
{
	int	i;
	int	buff_len;
	int	new_buff_len;

	i = 0;
	buff_len = gnl_strlen(buff_str);
	if (buff_len == next_line_end + 1)
		return ;
	if (!buff_str)
		return ;
	new_buff_len = buff_len - next_line_end;
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
}

void	*gnl_calloc(int size)
{
	unsigned char	*new_mem;

	new_mem = malloc(size);
	if (!new_mem)
		return (NULL);
	size--;
	while (size >= 0)
	{
		new_mem[size] = '\0';
		size--;
	}
	return (new_mem);
}
