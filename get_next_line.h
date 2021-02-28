/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 22:05:48 by pmitsuko          #+#    #+#             */
/*   Updated: 2021/02/28 09:08:11 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define R_LINE 1
# define R_EOF 0
# define R_ERROR -1

int		get_next_line(int fd, char **line);

void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_strcpy(char *dst, const char *src, size_t dstsize);

int		findchr(const char *s, char c);
char	*strjoin_free(char *s1, char *s2);
int		strcpy_line(char **line, char *str, int i);

#endif
