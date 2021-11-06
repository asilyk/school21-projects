CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

CP = cp

RM = rm -rf

LIBFT_NAME = ./libft/libft.a

LIBFT_HEADER = ./libft/libft.h

LIBFT_DIR = ./libft/

LIBFT_FILES = 	./libft/ft_memset				./libft/ft_bzero \
				./libft/ft_memcpy				./libft/ft_memmove \
				./libft/ft_memchr				./libft/ft_memcmp \
				./libft/ft_strlen				./libft/ft_strlcpy \
				./libft/ft_strlcat				./libft/ft_strchr \
				./libft/ft_strrchr				./libft/ft_strnstr \
				./libft/ft_strncmp				./libft/ft_atoi \
				./libft/ft_isalpha				./libft/ft_isdigit \
				./libft/ft_isalnum				./libft/ft_isascii \
				./libft/ft_isprint				./libft/ft_toupper \
				./libft/ft_tolower				./libft/ft_calloc \
				./libft/ft_strdup				./libft/ft_split \
				./libft/ft_substr				./libft/ft_strjoin \
				./libft/ft_strtrim				./libft/ft_split \
				./libft/ft_itoa					./libft/ft_strmapi \
				./libft/ft_putchar_fd			./libft/ft_putstr_fd \
				./libft/ft_putendl_fd			./libft/ft_putnbr_fd \
				./libft/ft_striteri				./libft/ft_lstnew_bonus \
				./libft/ft_lstadd_front_bonus	./libft/ft_lstsize_bonus \
				./libft/ft_lstlast_bonus		./libft/ft_lstadd_back_bonus \
				./libft/ft_lstdelone_bonus		./libft/ft_lstclear_bonus \
				./libft/ft_lstiter_bonus		./libft/ft_lstmap_bonus \

LIBFT_SRCS = $(addsuffix .c, $(LIBFT_FILES))

LIBFT_OBJS = $(addsuffix .o, $(LIBFT_FILES))

PRINTF_NAME = libftprintf.a

PRINTF_HEADER = ./includes/ft_printf.h

PRINTF_DIR = ./includes/

PRINTF_FILES = 	./sources/ft_printf \
				./sources/ft_putptr \
				./sources/ft_puthexnbr \
				./sources/ft_putunbr \

PRINTF_SRCS = $(addsuffix .c, $(PRINTF_FILES))

PRINTF_OBJ = $(addsuffix .o, $(PRINTF_FILES))

.PHONY: all clean fclean re

all: $(LIBFT_NAME) $(PRINTF_NAME)

$(LIBFT_NAME): $(LIBFT_SRCS) $(LIBFT_HEADER)
	make bonus -C $(LIBFT_DIR)

$(PRINTF_NAME): $(PRINTF_OBJ) $(LIBFT_NAME)
	$(CP) $(LIBFT_NAME) $(PRINTF_NAME)
	$(AR) $@ $(PRINTF_OBJ)

%.o: %.c $(PRINTF_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(PRINTF_DIR) -I$(LIBFT_DIR)

clean:
	$(RM) $(PRINTF_OBJ)
	make fclean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(PRINTF_NAME) $(LIBFT_NAME)

re: fclean all
