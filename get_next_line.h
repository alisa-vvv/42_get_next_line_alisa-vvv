/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                     :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: avaliull <avaliull@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:59:44 by avaliull          #+#    #+#             */
/*   Updated: 2024/12/06 17:54:39 by avaliull       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifdef BUFFER_SIZE
#  if BUFFER_SIZE > 8300000 || BUFFER_SIZE < 1
#   undef BUFFER_SIZE
#   define BUFFER_SIZE 42
#  endif
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
void	buff_zero(char **buff_str);
ssize_t	gnl_strlen(char *str);
char	*alloc_buff(char *buff_str, char *next_read, int read_re_val);
void	trim_buff(char **buff_str, ssize_t next_line_end);
void	*gnl_calloc(int size);

#endif
