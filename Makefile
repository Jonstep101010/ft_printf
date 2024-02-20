NAME		:= libftprintf.a

SRCS		:= ft_ltoa.c ft_vdprintf.c ft_printf.c put_utils.c

OBJS		:= $(SRCS:.c=.o)

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror

# Build all
all: $(NAME)

# Build object files from source files
.c.o:
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

# Build the final library
$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

# Clean object files
clean:
	rm -f $(OBJS) $(OBJS:.o=.d)

# Clean all generated files
fclean: clean
	rm -f $(NAME)

# Clean and build all
re: fclean all

.PHONY: all clean fclean re