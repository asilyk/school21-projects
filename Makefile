NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -c


AR = ar rcs

RM = rm -f

HEADERS = -I libft.h


FILES = 	ft_memset		ft_bzero		ft_memcpy \
			ft_memmove		ft_memchr		ft_memcmp \
			ft_strlen		ft_strlcpy		ft_strlcat \
			ft_strchr		ft_strrchr		ft_strnstr \
			ft_strncmp		ft_atoi			ft_isalpha \
			ft_isdigit		ft_isalnum		ft_isascii \
			ft_isprint		ft_toupper		ft_tolower \
			ft_calloc		ft_strdup		ft_split \
			ft_substr		ft_strjoin		ft_strtrim \
			ft_split		ft_itoa			ft_strmapi \
			ft_putchar_fd	ft_putstr_fd	ft_putendl_fd \
			ft_putnbr_fd

FILES_B = 	ft_lstnew		ft_lstadd_front \
			ft_lstsize		ft_lstlast \
			ft_lstadd_back	ft_lstdelone \
			ft_lstclear		ft_lstiter \
			ft_lstmap

SRCS = $(addsuffix .c, $(FILES))

SRCS_B = $(addsuffix .c, $(FILES_B))

OBJS = $(addsuffix .o, $(FILES))

OBJS_B = $(addsuffix .o, $(FILES_B))


.PHONY: bonus all clean fclean re

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@ $(HEADERS)

$(NAME): $(OBJS)
	$(AR) $@ $^

bonus: $(OBJS_B)
	$(AR) $(NAME) $^

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: clean all
