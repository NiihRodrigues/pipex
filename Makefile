NAME = pipex

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS = 
OBJS = ${SRCS:.c=.o}

all: $(LIBFT)
		$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o pipex		

$(LIBFT):
		$(MAKE) -C $(LIBFT_PATH)

$(NAME):
		$(CC) $(CFLAGS) $(SRCS) -o pipex

clean:
		@$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
		ar rc $(NAME) $(OBJS)
		@rm -rf pipex

re: fclean all

.PHONY: all clean fclean re
