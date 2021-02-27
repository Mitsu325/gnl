/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 08:07:32 by pmitsuko          #+#    #+#             */
/*   Updated: 2021/02/27 15:37:03 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int		fd[4];
	int		ret;
	int 	line;
	char	*buff = NULL;
		
	line = 0;
//	fd = open("test_files/test1", O_RDONLY);
//	fd = open("test_files/test2", O_RDONLY);
//	fd = open("test_files/test3", O_RDONLY);
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
	fd[0] = open("test_files/41_with_nl", O_RDONLY);
	fd[1] = open("test_files/42_with_nl", O_RDONLY);
	fd[2] = open("test_files/43_with_nl", O_RDONLY);
	fd[3] = open("test_files/nl", O_RDONLY);

	while ((ret = get_next_line(fd[0], &buff)) > 0)
	{
		printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
		free(buff);
	}
	printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
	if (ret == -1)
		printf("-----------\nError\n");
	else if (ret == 0)
		printf("-----------\nEnd of file\n");
	
	while ((ret = get_next_line(fd[1], &buff)) > 0)
	{
		printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
		free(buff);
	}
	printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
	if (ret == -1)
		printf("-----------\nError\n");
	else if (ret == 0)
		printf("-----------\nEnd of file\n");
	
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	close(fd[3]);

	return (0);
}
