# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 12:12:34 by aaoutem-          #+#    #+#              #
#    Updated: 2023/08/30 15:08:33 by aaoutem-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		:= gcc
NAME	:= cub
CFLAGS	:= -Wextra -Wall -g
framework :=  -framework OpenGL -framework AppKit
SRCS	:= main.c \
			src/init.c \
			src/castrays.c \
			src/utils/ft_itoa.c \
			src/utils/ft_min.c \
			src/utils/ft_strchr.c \
			src/utils/ft_strdup.c \
			src/utils/ft_strlen.c \
			src/utils/ft_split.c \
			src/utils/ft_strtrim.c

OBJS	:= ${SRCS:.c=.o}

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(framework)  -lmlx -lm -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re

# src/parsing/parse.c \
# src/parsing/pars_utls.c \
# src/parsing/parsing_fill.c \
# src/parsing/parsing_fill2.c \

# src/utils/ft_strtrim.c \