/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   get_next_line.h                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: avaliull <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/24 12:59:44 by avaliull       #+#    #+#                */
/*   Updated: 2024/11/29 13:16:36 by avaliull       ########   odam.nl        */
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

char	*get_next_line(int fd);
void	buff_zero(char *buff_str);
ssize_t	gnl_strlen(char *str);
char	*alloc_buff(char *buff_str, char *next_read);
char	*gnl_cat(char *buff_str, char *next_read);
void	trim_buff(char *buff_str, ssize_t next_line_end);

#endif
