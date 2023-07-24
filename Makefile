NAME = MiniShell

SRC = main.c ./builtins/aux/get_env.c ./builtins/aux/path_parser.c ./builtins/ft_cd.c ./builtins/ft_echo.c ./builtins/ft_export.c
OBJS = $(patsubst %.c, %.o, $(SRC))

##CFLAGS = -Wall -Wextra -Werror

INCLUDES = libft/libft.a

CC = cc

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) -g $(OBJS) $(INCLUDES) -o $(NAME)

$(OBJS): $(SRCS) ./includes/minishell.h
	$(CC) -c $(SRC) -I $(INCLUDES)

clean:
	make fclean -C libft
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re