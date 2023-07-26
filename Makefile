NAME = MiniShell

SRC = *.c ./builtins/aux/get_env.c ./builtins/aux/path_parser.c ./builtins/ft_cd.c ./builtins/ft_echo.c ./builtins/ft_export.c
OBJS = $(patsubst %.c, %.o, $(SRC))

##CFLAGS = -Wall -Wextra -Werror

INCLUDES = libft/libft.a

CC = cc

all: $(NAME)

$(NAME):
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo "HOLT! We are making a file!"
	@cc -o $(NAME) *.c ./libft/*.c ./builtins/*.c ./builtins/aux/*.c -lreadline
	

$(OBJS): $(SRCS) ./includes/minishell.h
	@$(CC) -c $(SRC) -I $(INCLUDES)

clean:
	@make fclean -C libft
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

makentest:
	@make re
	@./MiniShell

.PHONY: all bonus clean fclean re