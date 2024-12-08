/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                               :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: avaliull <avaliull@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:27:38 by avaliull          #+#    #+#             */
/*   Updated: 2024/12/08 20:00:46 by avaliull       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//void	buff_zero(char **buff_str)
//{
//	free(*buff_str);
//	*buff_str = NULL;
//}
//
//ssize_t	gnl_strlen(char *str)
//{
//	ssize_t	len;
//
//	if (!str)
//		return (0);
//	len = 0;
//	while (str[len] != '\0')
//		len++;
//	return (len);
//}
//
//char	*alloc_buff(char *buff_str, char *next_read, int read_re_val)
//{
//	int	i;
//
//	i = 0;
//	buff_str = gnl_calloc(read_re_val + 1);
//	if (!buff_str)
//		return (NULL);
//	while (i < read_re_val)
//	{
//		buff_str[i] = *next_read++;
//		i++;
//	}
//	return (buff_str);
//}

//void	*gnl_calloc(int size)
//{
//	unsigned char	*new_mem;
//
//	new_mem = malloc(size);
//	if (!new_mem)
//		return (NULL);
//	size--;
//	while (size >= 0)
//	{
//		new_mem[size] = '\0';
//		size--;
//	}
//	return (new_mem);
//}

void	trim_buff(char **buffer, ssize_t nl_index)
{
	ssize_t	i;
	ssize_t	new_buff_len;

	new_buff_len = BUFFER_SIZE - nl_index - 1;
	i = 0;
	while (i < new_buff_len)
	{
		(*buffer)[i] = (*buffer)[nl_index + i];
		i++;
	}
	while (i < BUFFER_SIZE)
	{
		(*buff_str)[i] = '\0';
		i++;
	}
}
