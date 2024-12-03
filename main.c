/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   main.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: avaliull <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/24 12:39:46 by avaliull       #+#    #+#                */
/*   Updated: 2024/12/03 20:13:15 by avaliull       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

//	

#include "get_next_line.h"

int	main(void)
{
	int	fd;
	char	*next_line;

//	fd = open("/home/avaliull/Projects/lvl1/get_next_line/attempt_01/test_files/txtfile", O_RDONLY);
//	fd = open("/home/avaliull/Projects/lvl1/get_next_line/attempt_01/test_files/alternate_line_nl_with_nl", O_RDONLY);
//	fd = open("/home/avaliull/Projects/lvl1/get_next_line/attempt_01/test_files/41_no_nl", O_RDONLY);
	fd = open("/home/avaliull/Projects/lvl1/get_next_line/attempt_01/test_files/variable_nls.txt", O_RDONLY);
	//int	i = 0;
	//while(i != 4)
	//{
	//	next_line = get_next_line(fd);
	//	i++;
	//	printf("next line is: %s\n", next_line);
	//}
	next_line = get_next_line(fd);
	printf("next line is: %s\n", next_line);
	while(next_line != NULL)
	{	
		next_line = get_next_line(fd);
		printf("next line is: %s\n", next_line);
	}

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
