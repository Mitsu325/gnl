/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 16:06:35 by pmitsuko          #+#    #+#             */
/*   Updated: 2021/02/28 16:37:10 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	str_len = ft_strlen(str);
	*line = ft_substr(str, 0, i);
	i++;
	ft_strcpy(str, str + i, str_len + 1);
	return (1);
}

int		get_read(int fd, char **line, char *buff, char **str)
{
	int	index_bl;
	int	ret;

	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		*(buff + ret) = '\0';
		if (*str)
			*str = strjoin_free(*str, buff);
		else
			*str = ft_strdup(buff);
		if ((index_bl = findchr(*str, '\n')) != -1)
		{
			strcpy_line_bl(line, *str, index_bl, buff);
			return (-42);
		}
	}
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	static char	*str[OPEN_MAX];
	char		*buff;
	int			ret;
	int			index;

	if (fd < 0 || fd >= MAX_FD || !line || BUFFER_SIZE < 1
			|| read(fd, *(str + fd), 0) < 0)
		return (R_ERROR);
	if (!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (R_ERROR);
	if (*(str + fd) && (index = findchr(*(str + fd), '\n')) != -1)
		return (strcpy_line_bl(line, *(str + fd), index, buff));
	if ((ret = get_read(fd, line, buff, &str[fd])) == -42)
		return (1);
	free(buff);
	if (*(str + fd))
	{
		*line = ft_strdup(*(str + fd));
		free(*(str + fd));
		*(str + fd) = NULL;
		return (ret);
	}
	*line = ft_strdup("");
	return (ret);
}
