# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmitsuko <pmitsuko@student.42sp.org>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/23 22:10:02 by pmitsuko          #+#    #+#              #
#    Updated: 2021/02/27 22:50:05 by pmitsuko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES	=	get_next_line.c get_next_line_utils.c  main.c

BONUS_FILES	=	get_next_line_bonus.c get_next_line_utils_bonus.c  main_bonus.c

CFLAGS	=	-Wall -Wextra -Werror -fsanitize=address

all:
	clang $(CFLAGS) -g3 -D BUFFER_SIZE=1000000000 $(FILES) -I get_next_line.h

bonus:
	gcc $(CFLAGS) -D BUFFER_SIZE=42 $(BONUS_FILES) -I get_next_line_bonus.h

debug:
	gcc -g $(FILES) -I get_next_line.h

object:
	gcc -c $(CFLAGS) get_next_line.c

normi:
	norminette get_next_line_bonus.c get_next_line_utils_bonus.c get_next_line_bonus.h

git:
	git add .
	git commit -m "$m"
	git push origin main
