/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   get_next_line.h                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: avaliull <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/24 12:59:44 by avaliull       #+#    #+#                */
/*   Updated: 2024/12/01 15:11:07 by avaliull       ########   odam.nl        */
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
char	*buff_zero(char *buff_str);
int	gnl_strlen(char *str);
char	*alloc_buff(char *buff_str, char *next_read, int read_re_val);
char	*gnl_cat(char *buff_str, char *next_read, int read_re_val);
void	trim_buff(char *buff_str, int next_line_end);
void	*gnl_calloc(int size);

#endif
