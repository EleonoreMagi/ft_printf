LIBFT = ./libft/libft.a

NAME = libftprintf.a

SRCS = ft_printf.c \
		src/ft_.c

OBJS = $(SRCS:/c=.o)

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./includes

$(NAME): $(OBJS)
		$(MAKE) bonus -C ./libft
		cp libft/libft.a $(NAME)
		$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
		ar -rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
		$(MAKE) clean -C ./libft
		rm -rf $(OBJS)

fclean: clean
		$(MAKE) fclean -C ./libft
		rm -rf $(NAME)

re: 	fclean all