NAME = pipex

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
SRCS = pipex.c main.c 
OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(LIBFT):
		$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(LIBFT) $(SRCS)
		$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

clean:
		@$(MAKE) -C $(LIBFT_PATH) fclean

fclean: clean
		@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
