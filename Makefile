CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRCS = ft_flags_utils_1.c	ft_flags_utils_2.c	ft_nbr_len.c		ft_print_c.c\
	   ft_print_d.c			ft_printf.c			ft_printf_utils.c	ft_printf_utoa.c\
	   ft_printf_utoa.c		ft_printf_xtoa.c	ft_print_p.c		ft_print_s.c\
	   ft_print_u.c			ft_print_x.c

OBJS_DIR = obj
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

$(OBJS_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus: all

$(NAME): $(LIBFT) $(OBJS_DIR) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean:
	make -C $(LIBFT_PATH) clean
	rm -rf $(OBJS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus libft
