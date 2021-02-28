/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 15:33:19 by pmitsuko          #+#    #+#             */
/*   Updated: 2021/02/27 15:50:26 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ptr_d;
	char	*ptr_s;
	size_t	i;

	if (!dst && !src)
		return (NULL);
	ptr_d = (char *)dst;
	ptr_s = (char *)src;
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

	len = ft_strlen(s1);
	if (!(s_alloc = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	ft_memcpy(s_alloc, s1, len);
	*(s_alloc + len) = '\0';
	return (s_alloc);
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