/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   get_next_line_utils.c                               :+:    :+:           */
/*                                                      +:+                   */
/*   By: avaliull <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/26 15:27:38 by avaliull       #+#    #+#                */
/*   Updated: 2024/11/26 15:46:32 by avaliull       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

void	buff_zero(char *buff_str)
{
	size_t	i;

	i = 0;
	while (buff_str[i])
	{
		buff_str[i] = 0;
		i++;
	}
}

size_t	gnl_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*gnl_cat(char *buff_str, char *next_read)
{
	char	*catted_str;
	size_t	buff_len;
	size_t	read_len;
	size_t	i;

	i = 0;
	read_len = gnl_strlen(next_read);
	/* THIS WILL BE SEPARATE */
	if (!buff_str)
	{
		malloc(read_len + 1);
		if (!buff_str)
			return (NULL);
		while (i < read_len + 1)
		{
			buff_str[i] = next_read++;
			i++;
		}
		return (buff_str);
	}
	/* THIS WILL BE SEPARATE */
	buff_len = gnl_strlen(buff_str);
	catted_str = malloc(read_len + buff_len + 1)
	if (!catted_str)
		return (NULL);
	while (i < buff_len)
	{
		catted_str[i] = buff_len[i];
		i++;
	}
	while (i < buff_len + read_len + 1)
	{
		catted_str[i] = read_len++;
		i++;
	}
	free(buff_len);
	return (catted_str);
}

char	*trim_buff(char *buff_str, size_t start)
{
	size_t	i;
	size_t	buff_len;
	char	*tmp_buff;

	buff_len = 
}
