/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:59:51 by toferrei          #+#    #+#             */
/*   Updated: 2024/06/06 13:39:20 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buf[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*result;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	result = NULL;
	i = 1;
	while (i > 0)
	{
		if (!*buf[fd])
		{
			i = read(fd, buf[fd], BUFFER_SIZE);
			if (i == 0)
				return (result);
			if (i == -1)
				return (NULL);
			buf[fd][i] = '\0';
		}
		result = ft_strjoin(result, buf[fd]);
		if (chrnline(result))
			break ;
	}
	return (result);
}

int main()
{
	int fd = open("file1.txt", O_RDONLY);
	int fd2 = open("file2.txt", O_RDONLY);
	char *line;
	char *line2;
	// printf("fd :%d\n", fd);
	while ((line = get_next_line(fd)) && (line2= get_next_line(fd2)))
	{
		printf("output :%s\n",line);
		free(line);
	}
	while ((line2= get_next_line(fd2)))
	{
		printf("output2 :%s\n",line2);
		free(line2);
	}
	// fd = open("file2.txt", O_RDONLY);
	// printf("fd :%d\n", fd);
	// while ((line = get_next_line(fd)))
	// {
	// 	printf("output :%s\n",line);
	// 	free(line);
	// }
}
