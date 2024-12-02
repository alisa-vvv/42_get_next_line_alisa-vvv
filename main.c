/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   main.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: avaliull <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/24 12:39:46 by avaliull       #+#    #+#                */
/*   Updated: 2024/12/02 20:03:51 by avaliull       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

//	

#include "get_next_line.h"

int	main(void)
{
	int	fd;
	char	*next_line;
	int	i = 0;

	fd = open("/home/avaliull/Projects/lvl1/get_next_line/attempt_01/txtfile", O_RDONLY);
	while(i != 7)
	{
		next_line = get_next_line(fd);
	//	int read_val;
	//	read_val = read(fd, next_line, BUFFER_SIZE);
	//	printf("read val is: %d\n", read_val);
		i++;
	}
	//next_line = get_next_line(fd);
	//printf("next line is: %s\n", next_line);
//	while(next_line != NULL)
//	{	
//		next_line = get_next_line(fd);
//		printf("next line is: %s\n", next_line);
//	}

	free(next_line);


////	FOR TESTING INDIVIDUAL FUNCS
//	static char	*buff_str;
//	char		*next_read = "test";
//
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
