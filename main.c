/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   main.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: avaliull <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/24 12:39:46 by avaliull       #+#    #+#                */
/*   Updated: 2024/11/28 19:41:42 by avaliull       ########   odam.nl        */
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
		printf("next line is: %s\n", next_line);
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
	return (0);
}
