CC				=		cc

CFLAGS			=	-Wall -Werror -Wextra

RM				=	rm -f

NAME			=	push_swap

LIBFT_DIR		=	libft

LIBFT			=	libft.a

INC 			= -I $(LIBFT_DIR)/ -I includes/

LIBFT_SOURCES	=	libft/ft_atoi.c \
					libft/ft_bzero.c \
					libft/ft_calloc.c \
					libft/ft_isalnum.c \
					libft/ft_isalpha.c \
					libft/ft_isascii.c \
					libft/ft_isdigit.c \
					libft/ft_isprint.c \
					libft/ft_itoa.c \
					libft/ft_lstadd_back_bonus.c \
					libft/ft_lstadd_front_bonus.c \
					libft/ft_lstclear_bonus.c \
					libft/ft_lstdelone_bonus.c \
					libft/ft_lstiter_bonus.c \
					libft/ft_lstlast_bonus.c \
					libft/ft_lstmap_bonus.c \
					libft/ft_lstnew_bonus.c \
					libft/ft_lstsize_bonus.c \
					libft/ft_memchr.c \
					libft/ft_memcmp.c \
					libft/ft_memcpy.c \
					libft/ft_memmove.c \
					libft/ft_memset.c \
					libft/ft_putchar_fd.c \
					libft/ft_putendl_fd.c \
					libft/ft_putnbr_fd.c \
					libft/ft_putstr_fd.c \
					libft/ft_split.c \
					libft/ft_strchr.c \
					libft/ft_strcmp.c \
					libft/ft_strdup.c \
					libft/ft_striteri.c \
					libft/ft_strjoin.c \
					libft/ft_strlcat.c \
					libft/ft_strlcpy.c \
					libft/ft_strlen.c \
					libft/ft_strmapi.c \
					libft/ft_strncmp.c \
					libft/ft_strnstr.c \
					libft/ft_strrchr.c \
					libft/ft_strtrim.c \
					libft/ft_substr.c \
					libft/ft_tolower.c \
					libft/ft_toupper.c \

LIBFT_HEADER	=	libft/libft.h \

SOURCES			=	sort_stack/ft_choose_best_elem.c \
					sort_stack/ft_fill_stack_b.c \
					sort_stack/ft_final_sort_stack.c \
					sort_stack/ft_find_triple.c \
					sort_stack/ft_make_push.c \
					sort_stack/ft_push_to_a.c \
					sort_stack/ft_sort_stack.c \
					stack_actions/ft_pa_action.c \
					stack_actions/ft_pb_action.c \
					stack_actions/ft_ra_action.c \
					stack_actions/ft_rb_action.c \
					stack_actions/ft_rr_action.c \
					stack_actions/ft_rra_action.c \
					stack_actions/ft_rrb_action.c \
					stack_actions/ft_rrr_action.c \
					stack_actions/ft_sa_action.c \
					stack_actions/ft_sb_action.c \
					stack_actions/ft_ss_action.c \
					stack_utilities/ft_add_back.c \
					stack_utilities/ft_add_front.c \
					stack_utilities/ft_find_last_stack_elem.c \
					stack_utilities/ft_find_penult_stack_elem.c \
					stack_utilities/ft_find_stack_size.c \
					stack_utilities/ft_init_stack.c \
					utilities/ft_error.c \
					utilities/ft_free.c \
					arguments_utilities/ft_check_arguments.c \
					arguments_utilities/ft_init_arguments.c \
					main.c \

HEADER			=	includes/push_swap.h \

$(NAME): $(SOURCES) $(HEADERS) $(LIBFT_SOURCES) $(LIBFT_HEADER)
	make -C $(LIBFT_DIR)/
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME) $(LIBFT_DIR)/$(LIBFT) $(INC)

.PHONY: all clean fclean re

all: $(NAME)

clean:
	make fclean -C $(LIBFT_DIR)/

fclean: clean
	$(RM) $(NAME)

re: fclean all