/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 09:16:17 by pmitsuko          #+#    #+#             */
/*   Updated: 2021/02/28 11:05:00 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (*(s + len))
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s_alloc;

	len = ft_strlen(s1) + 1;
	if (!(s_alloc = (char *)malloc(len * sizeof(char))))
		return (NULL);
	ft_strcpy(s_alloc, s1, len);
	return (s_alloc);
}

void	ft_strcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	if (!dst || !src)
		return ;
	i = 0;
	while (*(src + i) && dstsize && i + 1 < dstsize)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*new_str;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	if (s == NULL || s_len < start)
		return (ft_strdup(""));
	if (start + len < s_len)
		substr = (char *)malloc((len + 1) * sizeof(char));
	else
		substr = (char *)malloc((s_len - start + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	i = start;
	new_str = substr;
	while (i < (start + len) && *(s + i))
		*new_str++ = *(s + i++);
	*new_str = '\0';
	return (substr);
}
