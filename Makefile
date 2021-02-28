# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmitsuko <pmitsuko@student.42sp.org>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/23 22:10:02 by pmitsuko          #+#    #+#              #
#    Updated: 2021/02/28 14:45:23 by pmitsuko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES	=	get_next_line.c get_next_line_utils.c

BONUS_FILES	=	get_next_line_bonus.c get_next_line_utils_bonus.c

CFLAGS	=	-Wall -Wextra -Werror -fsanitize=address

all:
	clang $(CFLAGS) -g3 -D BUFFER_SIZE=1 $(FILES) main.c -I get_next_line.h

test:
	gcc -Wall -Werror -Wextra -D BUFFER_SIZE=42 $(FILES) main.c -I get_next_line.h

bonus:
	gcc $(CFLAGS) -D BUFFER_SIZE=42 $(BONUS_FILES) main_bonus.c -I get_next_line_bonus.h

debug:
	gcc -g $(FILES) -I get_next_line.h

object:
	gcc -c $(CFLAGS) get_next_line.c

normi:
	norminette $(FILES) $(BONUS_FILES) get_next_line.h get_next_line_bonus.h

git:
	git add .
	git commit -m "$m"
	git push origin main
