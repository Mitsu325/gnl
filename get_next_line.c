/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 08:27:16 by pmitsuko          #+#    #+#             */
/*   Updated: 2021/02/24 20:45:12 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(int fd, char **line)
{
	int			ret;
	char		buff[BUFFER_SIZE + 1];
	int			l = 0;
	char		*break_line;
//	static char	*str;

	if (fd < 0 || line == NULL)
	{
		printf("ERROR");
		return (-1);
	}
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		*(buff + ret) = '\0';
//		printf("%d: %s\n", l++, buff);
	}
	return (0);
}
