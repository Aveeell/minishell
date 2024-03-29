# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 12:19:43 by mkoch             #+#    #+#              #
#    Updated: 2022/05/13 12:19:45 by mkoch            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIBFT = libft/libft.a

CFLAGS = -Wall -Werror -Wextra

HEADER = minishell.h

RM = rm -rf

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I$(shell brew --prefix readline)/include -c $< -o $@ -I $(HEADER)

	
SRCS =	minishell.c\
		args_splitter.c\
		args_splitter_utils.c\
		get_cmd.c\
		cd.c\
		pwd.c\
		echo.c\
		env.c\
		list_lib.c\
		export.c\
		sig_handler.c\
		execve.c\
		unset.c\
		split_for_export.c\
		error_handler.c\
		get_env.c\
		pipe_handler.c\
		redirection_handler.c\
		parser.c\
		is_builtin.c\

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
