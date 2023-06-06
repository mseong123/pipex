SRCS_NAME = pipex pipex_utils init init_utils free

SRCS = $(SRCS_NAME:=.c)

OBJECTS = $(SRCS:.c=.o)

NAME = pipex

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -I ./libft $<	

$(NAME): $(OBJECTS)
	make bonus -C ./libft
	cc $(OBJECTS) -o $(NAME) -L./libft -lft

clean:
	make clean -C ./libft
	rm -f $(OBJECTS)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
