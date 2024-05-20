/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:42:45 by toferrei          #+#    #+#             */
/*   Updated: 2024/05/20 17:12:40 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char buf[BUFFER_SIZE + 1];
	char *result;
	int i;
	int j;
	
	printf("%s",buf);
	printf("%i", fd);
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return(NULL);
	result = NULL;
	j = 0;
	while(j == 0)
	{
		if(!*buf)
		{
			i = read(fd, buf, BUFFER_SIZE);
			if(i == -1)
			{
				ft_clean_buf(buf);
				return (result);
			}		
			if(i == 0)
				return(result);
			buf[i] = '\0';
			result = ft_strjoin(result, buf);
		}
		else
			result = ft_strjoin(result, buf);
		if (*buf)
			j = 1;
	}
	return(result);
}

int main()
{
	int fd = open("file.txt", O_RDONLY);
	char *line = get_next_line(fd);
	while (line)
	{
		printf("%s",line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}