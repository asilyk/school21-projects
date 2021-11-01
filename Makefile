CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -rf

LIBFT_NAME = ./libft/libft.a

LIBFT_HEADER = ./libft/libft.h

LIBFT_DIR = ./libft/

PRINTF_NAME = libftprintf.a

PRINTF_HEADER = ./includes/ft_printf.h

FILES =	./sources/ft_printf \
		./sources/ft_putptr \
		./sources/ft_puthexnbr \
		./sources/ft_putunbr \

SRCS = $(addsuffix .c, $(FILES))

OBJ = $(addsuffix .o, $(FILES))

.PHONY: all clean fclean re

all: $(LIBFT_NAME) $(PRINTF_NAME)

$(LIBFT_NAME): $(LIBFT_DIR)*.c $(LIBFT_DIR)*.h
	make bonus -C $(LIBFT_DIR)

$(PRINTF_NAME): $(OBJ) $(LIBFT_NAME) $(LIBFT_DIR)*.c $(LIBFT_DIR)*.h
	$(AR) $@ $(OBJ) $(LIBFT_DIR)*.o

%.o: %.c $(PRINTF_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(PRINTF_HEADER) -I$(LIBFT_HEADER)

clean:
	$(RM) $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(PRINTF_NAME) $(LIBFT_NAME)

re: fclean all
