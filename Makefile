NAME = minishell

LIBFT = libft/libft.a

CFLAGS = -Wall -Werror -Wextra -g

HEADER = minishell.h

RM = rm -rf

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I$(shell brew --prefix readline)/include -c $< -o $@ -I $(HEADER)

	
SRCS =	minishell.c\
		get_cmd.c cd.c\
		pwd.c\
		echo.c\
		env.c\
		list_lib.c\
		export.c\
		args_splitter.c\
		sig_handler.c\
		execve.c\
		unset.c\
		split.c\
		quotes.c\
		get_execve.c\
		error_handler.c\
		get_env.c\
		pipe_handler.c\
		redirection_handler.c\
		parser.c\
		is_builtin.c\
		str_join.c\

OBJS = $(SRCS:.c=.o) ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp $(LIBFT) $(NAME)
	$(CC) $(CFLAGS) -L$(shell brew --prefix readline)/lib -lreadline $(OBJS) -o $(NAME)

$(OBJS): minishell.h Makefile ./libft/*.c ./libft/*.h ./libft/Makefile

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean:	clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
