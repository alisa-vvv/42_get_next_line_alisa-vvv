/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   get_next_line.h                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: avaliull <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/24 12:59:44 by avaliull       #+#    #+#                */
/*   Updated: 2024/11/26 13:29:39 by avaliull       ########   odam.nl        */
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
char	*alloc_next_line(char *buff_str, size_t mem, size_t edge, int fd);
char	*file_reader(char *buff_str, int fd);

#endif
