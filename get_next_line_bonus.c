/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:59:51 by toferrei          #+#    #+#             */
/*   Updated: 2024/05/29 13:06:05 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*result[FOPEN_MAX];
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	result[fd] = NULL;
	i = 1;
	while (i > 0)
	{
		if (!*buf)
		{
			i = read(fd, buf, BUFFER_SIZE);
			if (i == 0)
				return (result[fd]);
			if (i == -1)
				return (NULL);
			buf[i] = '\0';
		}
		result[fd] = ft_strjoin(result[fd], buf);
		if (chrnline(result[fd]))
			break ;
	}
	return (result[fd]);
}

/*  int main()
{
	int fd = open("file1.txt", O_RDONLY);
	char *line;
	printf("fd :%d\n", fd);
	while ((line = get_next_line(fd)))
	{
		printf("output :%s\n",line);
		free(line);
	}
	fd = open("file2.txt", O_RDONLY);
	printf("fd :%d\n", fd);
	while ((line = get_next_line(fd)))
	{
		printf("output :%s\n",line);
		free(line);
	}
}*/
