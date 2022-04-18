NAME = minishell

CFLAGS = -Wall -Werror -Wextra

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

SRCS =	main.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -lreadline $(OBJS) -o $(NAME)

$(OBJS): minishell.h Makefile

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
