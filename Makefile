
CC 		:= gcc
NAME	:= cub3D
CFLAGS	:= -Wextra -Wall 
LIBMLX	:= $(HOME)/MLX42
LIBS	:= $(LIBMLX)/build/libmlx42.a ./libft.a -ldl -lglfw -pthread -lm
SRCS	:= main.c
OBJS	:= ${SRCS:.c=.o}

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re