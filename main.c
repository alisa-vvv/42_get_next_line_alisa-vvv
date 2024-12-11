/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   main.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: avaliull <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/24 12:39:46 by avaliull       #+#    #+#                */
/*   Updated: 2024/12/11 16:43:50 by avaliull       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

//	

#include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

int	main(void)
{
	int	fd;
	char	*next_line;
//
//	fd = open("./test_files/txtfile", O_RDONLY);
	fd = open("./test_files/alternate_line_nl_with_nl", O_RDONLY);
//	fd = open("./test_files/41_no_nl", O_RDONLY);
//	fd = open("./test_files/variable_nls.txt", O_RDONLY);
//	fd = open("./test_files/read_error.txt", O_RDONLY);
//	fd = open("./test_files/1char.txt", O_RDONLY);
//	fd = open("./test_files/one_line_no_nl.txt", O_RDONLY);
	int	i = 0;
	while(i != 10)
	{
		next_line = get_next_line(fd);
		i++;
		printf("next line is: %s\n", next_line);
		free(next_line);
	}

//	next_line = get_next_line(fd);
//	printf("next line is: %s\n", next_line);
//	while(next_line != NULL)
//	{	
//		next_line = get_next_line(fd);
//		printf("next line is: %s\n", next_line);
//	}
//
//	free(next_line);

////	FOR TESTING INDIVIDUAL FUNCS
//	static char	*buff_str;
//	char		*next_read;
////
//	int i = 0;
//	next_read = malloc(5);
//	while (i < 5)
//		next_read[i++] = 'a';
//	gnl_bzero(next_read, i);
//	printf("if im not dumb this works :%s\n", next_read);
//	buff_str = malloc(5);
//	buff_str[0] = 'a';
//	buff_str[1] = 'b';
//	buff_str[2] = 'c';
//	buff_str[3] = 'd';
//	buff_str[4] = 0;
//
//	printf("buff_str before: %s\n", buff_str);
//	printf("adress of buff_str before: %p\n", buff_str);
//	printf("next_read before: %s\n", next_read);
//	printf("adress of next_read before: %p\n", next_read);
//
////	gnl_cat(&buff_str, next_read, 4);
////	trim_buff(&buff_str, 2);
////	buff_zero(&buff_str);
//	
//	printf("buff_str after: %s\n", buff_str);
//	printf("adress of buff_str after: %p\n", buff_str);
//	printf("next_read after: %s\n", next_read);
//	printf("adress of next_read after: %p\n", next_read);
//	return (0);
}
