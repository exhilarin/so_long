NAME= so_long
SRCS= so_long.c utils.c map.c reachable.c get_next_line/get_next_line_utils.c get_next_line/get_next_line.c render.c movement.c
CC= cc
CFLAGS= -Wall -Wextra -Werror -g
MLX_PATH = ./mlx
MLX = $(MLX_PATH)/libmlx.a
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -lz -L/usr/X11R6/lib
OBJS= $(SRCS:.c=.o)
PRINTF= ./ft_printf/libftprintf.a

all: $(PRINTF) $(MLX) $(NAME) clear

$(PRINTF):
	make -C ./ft_printf

$(NAME): $(OBJS) $(PRINTF)
	$(CC) $(CFLAGS) -g $(OBJS) $(PRINTF) -o $(NAME) $(MLX_FLAGS)

$(MLX):
	curl -O https://cdn.intra.42.fr/document/document/28880/minilibx-linux.tgz
	tar -xvf minilibx-linux.tgz
	$(RM) $(MLX_PATH)
	mkdir -p $(MLX_PATH)
	mv minilibx-linux/* $(MLX_PATH)
	$(RM) -rf minilibx-linux
	$(RM) -rf minilibx-linux.tgz
	make -s -C $(MLX_PATH)


clear: clean
	clear

clean:
	rm -f $(OBJS) $(PRINTF)
	make clean -C ./ft_printf

fclean: clean
	rm -f $(NAME) $(PRINTF)
	make fclean -C ./ft_printf

re: fclean all

.PHONY: all clean re fclean clear
