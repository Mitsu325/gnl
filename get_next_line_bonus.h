/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 16:05:35 by pmitsuko          #+#    #+#             */
/*   Updated: 2021/02/28 16:43:08 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define MAX_FD 1024
# define R_LINE 1
# define R_EOF 0
# define R_ERROR -1

int		get_next_line(int fd, char **line);

size_t	ft_strlen(const char *s);
void	ft_strcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);

int		findchr(const char *s, char c);
char	*strjoin_free(char *s1, char *s2);
int		strcpy_line_bl(char **line, char *str, int i, char *buff);
int		get_read(int fd, char **line, char *buff, char **str);

#endif
