/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   get_next_line.h                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: avaliull <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/24 12:59:44 by avaliull       #+#    #+#                */
/*   Updated: 2024/11/28 13:46:06 by avaliull       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*	HEADERS I NEED	*/
# include <unistd.h>
# include <stdlib.h>
/*	HEADERS FOR TEST	*/
# include <stdio.h>
# include <fcntl.h>

//struct s_list
//{
//	void                    *content;
//	struct s_list   *next;
//}				t_list;

void	buff_zero(char *buff_str);
size_t	gnl_strlen(char *str);
char	*alloc_buff(char *buff_str, char *next_read, size_t read_len);
char	*gnl_cat(char *buff_str, char *next_read);
char	*trim_buff(char *buff_str, size_t start);

#endif
