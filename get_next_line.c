/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   get_next_line.c                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: avaliull <avaliull@student.codam.nl>                       +#+       */
/*                                                    +#+                     */
/*   Created: 2024/11/24 12:37:21 by avaliull       #+#    #+#                */
/*   Updated: 2024/12/03 20:56:28 by avaliull       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// TO DO: APPARENTLY READ ADDS MORE SYMBOls AFTTER FILE ENDS IF THE BUFFER IS TOO BIG (WHICH IS FUCKING DUMB AS FUCK, LITERALLY WHY)
// SO I AFTER EACH READ I SHOULD TRIM THE READ STRING AS FOLLOWING:
// 16 - READ_RE_VAL = AMOUNT OF CAHARACTERS TO ZERO FROM END OF NEXT_READ
// FUCKING SUPID SHIT I SPENT SO MCH TIME FIXING SOMETHING ELSE THI WAS THE PROBLEM RHTLAHFDHVFG
// wrong, it just doesnt overwrite anything. dumbass
// if i read 16 into a buffer of 20, index 15-19 are going to be garbage values. theyre just not overwritten bestie
// just how c is. the answer is c. its just c. dont check for null. ever.
// you think malloc cleans your fucking memory area????
// dumbass, nothing gets overwritten. its just saying 'here you are, heres some memory', you expect c to clean your fucking house as well?>

// REC_READ OVERWRITES IT'S OWN RESULT, CAUSING ISSUES WITH VARIABLE LINES.
// THIS IS PROBABLY BEST GOTTEN RID OF BY REWEITING IT SO THERE'S NO RECURSION. OR FIX IT SO IT ALWAYS PASSES UP THE LAST RESULT
// I THINK THAT CAN BE ACHIVED WITH AN IF CHECK THAT RETURNS -1 IF -1 IS RETURNED FROM LAST REC_READ (REC_READ WOULD BE INT IN THIS CASE)

char	*rec_read(char **buff_str, int fd, int *next_line_end)
{
	char		next_read[BUFFER_SIZE + 1];
	int		read_re_val;
	int		i;

	read_re_val = read(fd, next_read, BUFFER_SIZE);
	if (read_re_val == 0)
		return (*buff_str);
	gnl_cat(buff_str, next_read, read_re_val);
	if (!(*buff_str))
		return (NULL);
	i = 0;
//	printf("*buff_str here: %s\n", *buff_str);
	while ((*buff_str)[i] != '\0')
	{
		if ((*buff_str)[i] == '\n')
		{
//			printf("are we in the loop\n");
			*(next_line_end) = i;
//			printf("value in loop: %d\n", *next_line_end);
			return (*buff_str);
		}
		i++;
	}
	if ((*buff_str)[i] == '\0')
		rec_read(buff_str, fd, next_line_end);
	*next_line_end = gnl_strlen(*buff_str) - 1;
	return (*buff_str);
}

static char	*find_nl(char **buff_str, int *next_line_end, int read_val, int fd)
{
	char	*next_line;
	int	i;

	while ((*buff_str)[*next_line_end] != '\0')
	{
		if ((*buff_str)[*next_line_end] == '\n')
			break ;
		(*next_line_end)++;
	}
//	printf("checking buff_str: %s\n", *buff_str);
	//if (*next_line_end == read_val)
	read_val++;
	if (*next_line_end == gnl_strlen(*buff_str))
		//if (!rec_read(buff_str, fd, next_line_end))
		if (!rec_read(buff_str, fd, next_line_end))
			return (NULL);
//	printf("line end: %d\n", *next_line_end);
	/* I think I have to put thuis part as a separate function and use it here and in the rec_read, returning either rec_read or this*/
	next_line = gnl_calloc(*next_line_end + 2);
	if (!next_line)
		return (NULL);
	i = 0;
	while (i <= *next_line_end && (*buff_str)[i])
	{
		next_line[i] = (*buff_str)[i];
		i++;
	}
	if (i == gnl_strlen(*buff_str))
		*next_line_end = -1;
	/* The pount is that rec_read would return a next_line by itself and clean the buffer properly. I think? this feels like nonsense */
	if (*next_line_end == -1)
		buff_zero(buff_str);
	else if (*buff_str)
		trim_buff(buff_str, *next_line_end);
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*buff_str;
	char		next_read[BUFFER_SIZE + 1];
	int		read_re_val;
	int		next_line_end;
	char		*next_line;

	//printf("checking buff_str in beg: %s\n", buff_str);
	read_re_val = read(fd, next_read, BUFFER_SIZE);
	next_read[read_re_val] = '\0';
	//printf("next_read in beg: %s\n", next_read);
	if (read_re_val > 0 && !buff_str)
		buff_str = alloc_buff(buff_str, next_read, read_re_val);
	else if (read_re_val <= 0 && !buff_str)
		return (NULL);
	else
		gnl_cat(&buff_str, next_read, read_re_val);
	//printf("buff_str after cat: %s\n", buff_str);
	if (!buff_str)
		return (NULL);
	next_line_end = 0;
	next_line = find_nl(&buff_str, &next_line_end, read_re_val, fd);
	if (!next_line && buff_str)
	{
		buff_zero(&buff_str);
		return (NULL);
	}
	return (next_line);
}
