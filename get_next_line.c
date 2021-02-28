/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 08:27:16 by pmitsuko          #+#    #+#             */
/*   Updated: 2021/02/28 12:35:31 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		findchr(const char *s, char c)
{
	int		i;

	i = 0;
	while (*(s + i) && *(s + i) != c)
		i++;
	if (*(s + i) != c)
		return (-1);
	return (i);
}

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
	ft_strcpy(new_str, s1, s1_len + 1);
	free(s1);
	s1 = NULL;
	ft_strcpy(new_str + s1_len, s2, s2_len + 1);
	*(new_str + (s1_len + s2_len)) = '\0';
	return (new_str);
}

int		strcpy_line_bl(char **line, char *str, int i, char *buff)
{
	int str_len;

	free(buff);
	buff = NULL;
	str_len = ft_strlen(str);
	*line = ft_substr(str, 0, i);
	i++;
	ft_strcpy(str, str + i, str_len + 1);
	return (1);
}

void	strcpy_line(char **line, char *buff, char *str)
{
	free(buff);
	buff = NULL;
	if (str)
	{
		*line = ft_strdup(str);
		free(str);
		str = NULL;
		return ;
	}
	*line = ft_strdup("");
}

int		get_next_line(int fd, char **line)
{
	static char	*str = NULL;
	char		*buff;
	int			ret;
	int			index_bl;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, str, 0) < 0
			|| !(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (R_ERROR);
	if (str && (index_bl = findchr(str, '\n')) != -1)
		return (strcpy_line_bl(line, str, index_bl, buff));
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		*(buff + ret) = '\0';
		str = strjoin_free(str, buff);
		if ((index_bl = findchr(str, '\n')) != -1)
			return (strcpy_line_bl(line, str, index_bl, buff));
	}
	strcpy_line(line, buff, str);
	return (ret);
}
