/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:42:47 by toferrei          #+#    #+#             */
/*   Updated: 2024/05/20 17:18:01 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		return (++i);
	return (i);
}

void ft_clean_buf(char *buf)
{
	int i; // mistake is here
	int l;
	int j;
	
	i = ft_strlen(buf);
	j = 0;
	l = 0;
	printf("\n buffer : %s \n", buf);
	if (buf[i] == '\0')
	{
		buf[0] = '\0';
		return ;
	}
	while (buf[l])
		l++;
	buf[i++] = 0;
	while (i < l)
		buf[j++] = buf[i++];
	buf[j]='\0';
	printf("%s buffer",buf);
}


char *ft_strjoin(char *s1, char *s2)
{
	char	*s_res;
	int		i;
	int		j;
	int		soma;

	j = 0;
	i = 0;

	soma = ft_strlen(s1) + ft_strlen(s2);
	s_res = malloc((soma + 1));
	if (s1)
	{	while (s1[i])
		{
		s_res[i] = s1[i];
		i++;
		}
	}
	while (i < soma)
		s_res[i++] = s2[j++];
	s_res[i] = '\0';
	if (s1)
		free (s1);
	ft_clean_buf(s2);
	return (s_res);
}
