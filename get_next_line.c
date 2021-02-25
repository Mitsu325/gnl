/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 08:27:16 by pmitsuko          #+#    #+#             */
/*   Updated: 2021/02/25 20:43:44 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*strjoin_free(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*new_str;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(new_str = (char *)malloc((s1_len + s2_len + 1) * sizeof(char))))
		return (NULL);
	ft_memcpy(new_str, s1, s1_len);
	free(s1);
	s1 = NULL;
	ft_memcpy(new_str + s1_len, s2, s2_len);
	*(new_str + (s1_len + s2_len)) = '\0';
	return (new_str);
}

int		get_next_line(int fd, char **line)
{
	static char	*str = NULL;
	char		buff[BUFFER_SIZE + 1];
	int			ret;
	int			index_bl;

	if (fd < 0 || line == NULL)
		return (R_ERROR);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		*(buff + ret) = '\0';
		str = strjoin_free(str, buff);
		if ((index_bl = findchr(str, '\n')) != -1)
		{
			printf(">> %s \n\n", str);
			return (R_LINE);
		}
	}
	printf("FINAL>> %s \n\n", str);
	return (0);
}
