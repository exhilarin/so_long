NAME= so_long
SRCS= so_long.c 
	\ utils.c 
	\ map.c
	\ move.c
	\ get_next_line/get_next_line_utils.c 
	\ get_next_line/get_next_line.c 

CC= cc
CFLAGS= -Wall -Wextra -Werror
OBJS= $(SRCS:.c=.o)

all: $(NAME) clear

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clear: clean
	clear

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean clear
