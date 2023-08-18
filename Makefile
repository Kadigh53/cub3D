# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbzizal <sbzizal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/16 10:28:52 by sbzizal           #+#    #+#              #
#    Updated: 2023/08/18 12:04:44 by sbzizal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

CFILES = cub3D.c  ft_split.c ft_itoa.c ft_strtrim.c\
./parsing/parse.c ./parsing/parsing_fill.c ./parsing/pars_utls.c ./parsing/parsing_fill2.c\
./parsing/parsing_print.c\
./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c\

OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES) cub3D.h
	$(CC) $(CFLAGS) $(OFILES) -o $(NAME) -lmlx -framework OpenGL -framework AppKit
	
.c.o: cub3D.h
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re