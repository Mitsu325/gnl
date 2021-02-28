/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 08:07:32 by pmitsuko          #+#    #+#             */
/*   Updated: 2021/02/28 14:31:08 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int		fd;
	int		ret;
	int 	line;
	char	*buff = NULL;
		
	line = 0;
//	fd = open("test_files/test1", O_RDONLY);
//	fd = open("test_files/test2", O_RDONLY);
	fd = open("test_files/test3", O_RDONLY);
//	fd = open("test_files/test4", O_RDONLY);
//	fd = open("test_files/test5", O_RDONLY);
//	fd = open("test_files/test6", O_RDONLY);
//	fd = open("test_files/test7", O_RDONLY);
//	fd = open("test_files/nl", O_RDONLY);
//	fd = open("test_files/empty", O_RDONLY);
//	fd = open("test_files/41_no_nl", O_RDONLY);
//	fd = open("test_files/41_with_nl", O_RDONLY);
//	fd = open("test_files/42_no_nl", O_RDONLY);
//	fd = open("test_files/42_with_nl", O_RDONLY);
//	fd = open("test_files/43_no_nl", O_RDONLY);
//	fd = open("test_files/43_with_nl", O_RDONLY);
//	fd = open("test_files/alternate_line_nl_no_nl", O_RDONLY);
//	fd = open("test_files/alternate_line_nl_with_nl", O_RDONLY);
//	fd = open("test_files/big_line_no_nl", O_RDONLY);
//	fd = open("test_files/big_line_with_nl", O_RDONLY);
//	fd = open("test_files/multiple_line_no_nl", O_RDONLY);
//	fd = open("test_files/multiple_line_with_nl", O_RDONLY);
//	fd = open("test_files/multiple_nlx5", O_RDONLY);
//	fd = open("test_files/long-3x", O_RDONLY);

	printf("fd = %d\n", fd);

//	get_next_line(fd, &buff);

/*	while ((ret = get_next_line(fd, &buff)) > 0)
	{
		printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
		free(buff);
	}
*/
	while ((ret = get_next_line(fd, &buff)) > 0)
	{
//		printf("LER");
		printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
		free(buff);
	}
	printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
	if (ret == -1)
		printf("-----------\nError\n");
	else if (ret == 0)
		printf("-----------\nEnd of file\n");
	close(fd);

	return (0);
}
