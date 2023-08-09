NAME			=	minishell

HEADERS_DIR 	=	./includes/
SOURCES_DIR		=	./builtins/

HEADERS_LIST	=	minishell.h
SOURCES_LIST	=	ft_cd.c ft_cwd.c ft_echo.c \
					ft_env.c ft_exit.c ft_export.c \
					ft_unset.c

HEADERS			=	${addprefix ${HEADERS_DIR}, ${HEADERS_LIST}}
SOURCES			=	${addprefix ${SOURCES_DIR}, ${SOURCES_LIST}}
INCLUDES		=	-I ${HEADERS_DIR} -I ${LIBFT_HEADERS}

OBJECTS_DIR		=	./objs/
OBJECTS_LIST	=	${patsubst %.c, %.o, ${SOURCES_LIST}}
OBJS			=	$(SOURCES_LIST:.c=.o)
OBJECTS			=	${addprefix ${OBJECTS_DIR}, ${OBJECTS_LIST}}

LIBFT			=	${LIBFT_DIR}libft.a
LIBFT_DIR		=	./libft/
LIBFT_HEADERS	=	${LIBFT_DIR}includes/

CC				=	cc 
CFLAGS			=	-Wall -Werror -Wextra -g3

all: ${NAME}

libft: ${LIBFT}

${NAME}:		${LIBFT} ${OBJECTS_DIR} ${OBJECTS}
	${CC} ${CFLAGS} main.c ${OBJECTS} ${LIBFT} ${INCLUDES} -o ${NAME} -lreadline
	@echo "\033[1;92mminishell created successfully!\033[0m"

${OBJECTS_DIR}:
	mkdir -p ${OBJECTS_DIR}

${OBJECTS_DIR}%.o : ${SOURCES_DIR}%.c ${HEADERS}
	${CC} ${CFLAGS} -c ${INCLUDES} $< -o $@

${LIBFT}:
	clear && make -sC ${LIBFT_DIR}

clean:
	clear
	@make -sC ${LIBFT_DIR} clean
	@echo "Removing minishell objects..."
	@rm -rf ${OBJECTS_DIR}

fclean: clean
	@echo "Removing Libft..."
	@rm -rf ${LIBFT}
	@echo "\033[31mLibft removed successfully!\033[0m"
	@echo "Removing minishell..."
	@rm -rf ${NAME}
	@echo "\033[31mminishell removed successfully!\033[0m"

re:	fclean all

run:	
#	gcc -g3 main.c ./libft/*.c ./builtins/ft_echo.c ./builtins/ft_pwd.c ./builtins/ft_env.c ./builtins/ft_cd.c ./builtins/aux/*.c -lreadline -o minishell
	clear
	@gcc -g3 main.c builtins/ft_unset.c builtins/ft_export.c ./utils/error_msg.c ./libft/*.c ./hashmap/ht*.c ./builtins/ft_exit.c ./builtins/ft_echo.c ./builtins/ft_cd.c ./builtins/ft_pwd.c ./builtins/ft_env.c ./builtins/aux/*.c -I./includes/ -lreadline -o minishell
#	gcc main.c ./libft/*.c ./builtins/*echo* ./builtins/*pwd.c ./builtins/aux/*.c -lreadline -o minishell

.PHONY:		all, clean, fclean, re

#-exec set follow-fork-mode child

#valgrind --show-leak-kinds=all --track-origins=yes --leak-check=full -s