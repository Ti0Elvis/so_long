NAME = libft.a
FLAGS = -Wall -Wextra -Werror

FILES = ./ft_bzero.c \
		./ft_calloc.c \
		./ft_memset.c \
		./ft_strchr.c \
		./ft_strdup.c \
		./ft_strlen.c \
		./ft_strncmp.c \
		./ft_strtrim.c \
		./ft_substr.c \
		./ft_printf/ft_printf.c \
		./ft_printf/ft_putchar.c \
		./ft_printf/ft_putfn.c \
		./ft_printf/ft_puthex_lowercase.c \
		./ft_printf/ft_puthex_uppercase.c \
		./ft_printf/ft_putnbr.c \
		./ft_printf/ft_putpointer.c \
		./ft_printf/ft_putstr.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c

OBJ = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
