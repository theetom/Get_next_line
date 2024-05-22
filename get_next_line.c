/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etom <etom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:42:45 by toferrei          #+#    #+#             */
/*   Updated: 2024/05/22 11:30:09 by etom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char buf[BUFFER_SIZE + 1];
	char *result;
	int i;
	int j;
	
	// printf("1st buf :%s\n",buf);
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return(NULL);
	result = NULL;
	j = 0;
	while(j == 0)
	{
		if(!*buf)
		{
			
			i = read(fd, buf, BUFFER_SIZE);
				// printf("1st buf :%s\nread:%d\n",buf, i);
			if(i == -1)
			{
				ft_clean_buf(buf);
				return (result);
			}		
			if(i == 0)
				return(result);
			buf[i] = '\0';
			// printf("b result :%s\n", result);
			result = ft_strjoin(result, buf);
			// printf("a result :%s\n", result);
		}
		else
			result = ft_strjoin(result, buf);
		if (*buf)
			j = 1;
	}
	return(result);
}

// int main()
// {
// 	int fd = open("file.txt", O_RDONLY);
// 	char *line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("output :%s\n",line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	free(line);
// }