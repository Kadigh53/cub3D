# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/16 10:28:52 by sbzizal           #+#    #+#              #
#    Updated: 2023/09/26 08:54:58 by aaoutem-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      := cc

NAME    := cub3D

CFLAGS  := -Wextra -Wall -Werror

LIBMLX  := $(HOME)/MLX42

GLFWLIB := $(HOME)/.brew/opt/glfw/lib/

LIBS    := ./libmlx42/libmlx42.a  -ldl -lglfw -pthread -lm

framework := -framework Cocoa -framework OpenGL -framework IOKit

SRCS    := cub3D.c\
	src/parsing/parse.c\
	src/parsing/pars_utls.c\
	src/parsing/parsing_fill.c\
	src/parsing/parsing_fill2.c\
	src/parsing/parsing_fill3.c\
	src/raycastin/init.c\
	src/raycastin/castrays.c\
	src/raycastin/map_datexture.c\
	src/raycastin/castrays_gears.c\
	src/utils/ft_strdup.c\
	src/utils/ft_itoa.c\
	src/utils/ft_split.c\
	src/utils/ft_calloc.c\
	src/utils/ft_strtrim.c\
	src/utils/utils_draw.c\
	src/movment/movment.c\
	src/movment/mv_player.c\
	src/mini_map/mini_map.c\
	get_next_line/get_next_line.c\
	get_next_line/get_next_line_utils.c\
	void.c

B_SRCS		:= cub3D.c\
	src/parsing/parse.c\
	src/parsing/pars_utls.c\
	src/parsing/parsing_fill.c\
	src/parsing/parsing_fill2.c\
	src/parsing/parsing_fill3.c\
	src/raycastin/init.c\
	src/raycastin/castrays.c\
	src/raycastin/map_datexture.c\
	src/raycastin/castrays_gears.c\
	src/utils/ft_strdup.c\
	src/utils/ft_itoa.c\
	src/utils/ft_split.c\
	src/utils/ft_calloc.c\
	src/utils/ft_strtrim.c\
	src/utils/utils_draw.c\
	src/movment/movment.c\
	src/movment/mv_player.c\
	src/mini_map/mini_map.c\
	get_next_line/get_next_line.c\
	get_next_line/get_next_line_utils.c\
	plus_bonus.c

OBJS    := ${SRCS:.c=.o}
B_OBJS    := ${B_SRCS:.c=.o}

all: $(NAME)

bonus: $(B_OBJS) cub3D.h
	$(CC) $(B_OBJS) $(LIBS) $(framework) -L$(GLFWLIB) -o cub3D

%.o: %.c cub3D.h
	$(CC) $(CFLAGS) -o $@ -c $< 

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) $(framework) -L$(GLFWLIB) -o cub3D

clean:
	rm -rf $(OBJS) $(B_OBJS)

fclean: clean
	@rm -rf $(NAME)

re: clean all
