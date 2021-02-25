/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 09:16:17 by pmitsuko          #+#    #+#             */
/*   Updated: 2021/02/25 20:18:47 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ptr_d;
	char	*ptr_s;
	size_t	i;

	ptr_d = (char *)dst;
	ptr_s = (char *)src;
	if (!dst && !src)
			return (NULL);
	i = 0;
	while (i < n)
	{
		*(ptr_d + i) = *(ptr_s + i);
		i++;
	}
	return (dst);
}

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
	s_alloc = (char *)malloc(len * sizeof(char));
	if (s_alloc == NULL)
		return (NULL);
	ft_memcpy(s_alloc, s1, len);
	return (s_alloc);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;

	i = 0;
	ch = c;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == ch)
			return ((char *)s + i);
		i++;
	}
	if (ch == '\0')
			return ((char *)s + i);
	return (NULL);
}
