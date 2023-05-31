NAME		:= libftprintf.a

VPATH		:= src/
SRCS		:= ft_printf.c put_utils.c

INC			:= -I ./include -I ./libft
LIBFT		:= $(LIBFT_DIR)/libft.a
LIBFT_DIR	:= ./libft

BUILD_DIR	:= .build
OBJS		:= $(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))

CC			:= clang
CFLAGS		:= -Wall -Wextra -Werror

all: $(NAME)

$(BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -MMD -MP $(INC) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	cp libft/libft.a $@
	ar -rcs $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS) $(OBJS:.o=.d)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
