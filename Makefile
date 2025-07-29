NAME = so_long

SRCS = so_long.c utils.c map.c reachable.c render.c movement.c error.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

MLX_PATH = ./mlx
PRINTF_PATH = ./ft_printf
GNL_PATH = ./get_next_line

MLX = $(MLX_PATH)/libmlx.a
PRINTF = $(PRINTF_PATH)/libftprintf.a
GNL = $(GNL_PATH)/get_next_line.c $(GNL_PATH)/get_next_line_utils.c

MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -lz -L/usr/X11R6/lib

all: $(PRINTF) $(MLX) $(NAME)

$(NAME): $(GNL) $(OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(GNL) $(OBJS) $(PRINTF) -o $(NAME) $(MLX_FLAGS)

$(PRINTF):
	@echo "Checking ft_printf..."
	@if [ ! -d "$(PRINTF_PATH)" ]; then \
		echo "Cloning ft_printf..."; \
		git clone https://github.com/ilyasguney/printf.git $(PRINTF_PATH); \
	else \
		echo "ft_printf exists."; \
	fi
	@make -C $(PRINTF_PATH)

$(GNL):
	@echo "Checking get_next_line..."
	@if [ ! -d "$(GNL_PATH)" ]; then \
		echo "Cloning get_next_line..."; \
		git clone https://github.com/ilyasguney/get_next_line.git $(GNL_PATH); \
	else \
		echo "get_next_line exists."; \
	fi

$(MLX):
	@echo "Extracting local minilibx..."
	@if [ ! -f "minilibx-linux.tgz" ]; then \
		echo "Error: minilibx-linux.tgz not found."; \
		exit 1; \
	fi
	@rm -rf $(MLX_PATH)
	@tar -xzf minilibx-linux.tgz
	@mkdir -p $(MLX_PATH)
	@mv minilibx-linux/* $(MLX_PATH)
	@rm -rf minilibx-linux
	@make -s -C $(MLX_PATH)

clean:
	rm -f $(OBJS)
	@make clean -C $(PRINTF_PATH)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(PRINTF_PATH)
	rm -rf $(PRINTF_PATH) $(GNL_PATH)

re: fclean all

.PHONY: all clean fclean re
