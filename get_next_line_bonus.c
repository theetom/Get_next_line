/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etom <etom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:59:51 by toferrei          #+#    #+#             */
/*   Updated: 2024/05/25 11:07:58 by etom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*result[3000];
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
			if (i == -1 || i == 0)
				return (result[fd]);
			buf[i] = '\0';
		}
		result[fd] = ft_strjoin(result[fd], buf);
		if (chrnline(result[fd]))
			break ;
	}
	return (result[fd]);
}

 int main()
{
	int fd = open("file.txt", O_RDONLY);
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
}
