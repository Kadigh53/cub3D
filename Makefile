# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/17 02:50:34 by aaoutem-          #+#    #+#              #
#    Updated: 2023/08/19 08:51:43 by aaoutem-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #





# cc = cc
# rm = rm -rf
# flags = -Wall -Wextra #-Werror
# framework = -lmlx -Imlx -framework Cocoa -framework OpenGL -framework IOKit
# header = cub3d.h

# SRC = main.c

# OBJ_F = $(SRC:.c=.o)

# all : $(NAME)

# $(NAME) : $(OBJ_F)
# 	$(cc) $(flags) $(OBJ_F) -lmlx $(framework) -o cub3D

# %.o: %.c $(header)
# 	$(cc) $(flags) -Imlx -c $< -o $@

# clean :
# 	$(rm) $(OBJ_F)

# fclean : clean
# 	$(rm) $(NAME)

# re : fclean all

# .PHONY : all clean fclean re















NAME = cub3D

CC = cc
RM = rm -rf
flags = -Wall -Wextra #-Werror
glfw = $(HOME)/.brew/opt/glfw
MLX42 = $(HOME)/MLX42
LIBS = $(MLX42)/build/libmlx42.a -lm -L$(glfw) -ldl 
framework = -framework Cocoa -framework OpenGL -framework IOKit
header =  cub3d.h $(HOME)/MLX42/include/MLX42/MLX42.h 

SRC = main.c

OBJ_F = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ_F)
	$(CC) $(flags) $(OBJ_F) $(LIBS) $(framework) -o cub

%.o: %.c $(header)
	$(CC) $(flags) -c $< -o $@

clean :
	$(RM) $(OBJ_F)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re