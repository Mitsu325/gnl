# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmitsuko <pmitsuko@student.42sp.org>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/23 22:10:02 by pmitsuko          #+#    #+#              #
#    Updated: 2021/02/24 20:28:37 by pmitsuko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES	=	get_next_line.c get_next_line_utils.c  main.c

CFLAGS	=	-Wall -Wextra -Werror

all:
	gcc $(CFLAGS) -D BUFFER_SIZE=32 $(FILES) -I get_next_line.h

debug:
	gcc -g $(FILES) -I get_next_line.h

object:
	gcc -c $(CFLAGS) get_next_line.c

git:
	git add .
	git commit -m "$m"
	git push origin main
