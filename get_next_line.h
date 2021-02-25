/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 22:05:48 by pmitsuko          #+#    #+#             */
/*   Updated: 2021/02/25 20:48:09 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 8
#endif

# define R_LINE 1
# define R_EOF 0
# define R_ERROR -1

int		get_next_line(int fd, char **line);

void    *ft_memcpy(void *dst, const void *src, size_t n);
size_t  ft_strlen(const char *s);
char    *ft_strdup(const char *s1);
int		findchr(const char *s, char c);

#endif
