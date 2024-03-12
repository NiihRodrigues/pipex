NAME = pipex

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS = pipex.c main.c 
OBJS = ${SRCS:.c=.o}

all: $(LIBFT)
		$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o pipex		

$(LIBFT):
		$(MAKE) -C $(LIBFT_PATH)

$(NAME):
		$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
		ar rc $(NAME) $(OBJS)

clean:
		@$(MAKE) -C $(LIBFT_PATH) fclean

fclean: clean
		@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
