NAME = minishell

LIBFT = libft/libft.a

CFLAGS = -Wall -Werror -Wextra

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

SRCS =	main.c\
		parse.c\
		programs.c\
		binary.c\
		# signals.c\

OBJS = $(SRCS:.c=.o) ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp $(LIBFT) $(NAME)
	$(CC) $(CFLAGS) -lreadline $(OBJS) -o $(NAME)

$(OBJS): minishell.h Makefile ./libft/*.c ./libft/*.h ./libft/Makefile

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)

fclean:	clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re