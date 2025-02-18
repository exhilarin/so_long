NAME = so_long
SRCS = so_long.c utils.c map.c reachable.c render.c movement.c
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLX_PATH = ./mlx
PRINTF_PATH = ./ft_printf
GNL_PATH = ./get_next_line
MLX = $(MLX_PATH)/libmlx.a
PRINTF = $(PRINTF_PATH)/libftprintf.a
GNL = $(GNL_PATH)/get_next_line.c $(GNL_PATH)/get_next_line_utils.c
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -lz -L/usr/X11R6/lib
OBJS = $(SRCS:.c=.o)

all: $(PRINTF) $(MLX) $(NAME) clear

$(NAME): $(GNL) $(OBJS) $(PRINTF)
	$(CC) $(CFLAGS) -g $(GNL) $(OBJS) $(PRINTF) -o $(NAME) $(MLX_FLAGS)

$(PRINTF):
	@echo "Checking printf repository..."
	@if [ ! -d "$(PRINTF_PATH)" ]; then \
		echo "Cloning printf repository..."; \
		git clone https://github.com/ilyasguney/printf.git $(PRINTF_PATH); \
	else \
		echo "printf repository already exists, skipping clone."; \
	fi
	@echo "Building printf library..."
	make -C $(PRINTF_PATH)

$(GNL):
	@echo "Checking get_next_line repository..."
	@if [ ! -d "$(GNL_PATH)" ]; then \
		echo "Cloning get_next_line repository..."; \
		git clone https://github.com/msgenan/get_next_line.git $(GNL_PATH); \
	else \
		echo "get_next_line repository already exists, skipping clone."; \
	fi
	@echo "Building get_next_line library..."


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
	make clean -C $(PRINTF_PATH)

fclean: clean
	rm -f $(NAME) $(PRINTF)
	make fclean -C $(PRINTF_PATH)

re: fclean all

.PHONY: all clean re fclean clear
