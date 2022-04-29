NAME = minishell

LIBFT = libft/libft.a

CFLAGS = -Wall -Werror -Wextra 

HEADER = minishell.h

RM = rm -rf

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I$(shell brew --prefix readline)/include -c $< -o $@ -I $(HEADER)

	
SRCS = minishell.c get_cmd.c command_init.c exec.c cd.c cwd.c __echo.c __env.c list_lib.c __export.c \
		args_splitter.c sig_handler.c execve.c __unset.c split.c quotes.c \
		files.c get_execve.c error_handler.c getenv.c pipe_handler.c redirection_handler.c \
		parser.c is_builtin.c str_join.c free_lst.c

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




# NAME = minishell
# LIBFT = libft/libft.a
# INC = minishell.h
# CFLAGS = -Wall -Wextra -Werror
# RM = rm -rf
# CC = cc

# FILES = minishell.c get_cmd.c command_init.c exec.c cd.c cwd.c __echo.c __env.c list_lib.c __export.c \
# 		args_splitter.c sig_handler.c execve.c __unset.c split.c quotes.c \
# 		files.c get_execve.c error_handler.c getenv.c pipe_handler.c redirection_handler.c \
# 		parser.c is_builtin.c str_join.c free_lst.c

# OBJS = $(FILES:.c=.o)

# all: $(NAME)

# $(NAME): $(OBJS) $(LIBFT)
# 	@$(CC)  $(OBJS) $(LIBFT) -L$(shell brew --prefix readline)/lib -lreadline -o $(NAME)
# 	@echo "minishell created"

# $(LIBFT):
# 	@make bonus -C libft

# %.o:%.c $(INC)
# 	@$(CC) $(CFLAGS) -I$(shell brew --prefix readline)/include -c $< -o $@ -I $(INC)
# 	@echo "compiling minishell ..."

# clean:
# 	@$(RM) $(OBJS)
# 	@make clean -C libft
# 	@echo "successfuly cleaned"

# fclean: clean
# 	@$(RM) $(NAME)
# 	@make fclean -C libft
# 	@echo "executable removed successfuly"

# re: fclean all
