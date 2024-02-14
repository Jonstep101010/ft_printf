# Output name
NAME		:= libftprintf.a

# Source files
VPATH		:= src/
SRCS		:= ft_vdprintf.c ft_printf.c put_utils.c

# Include directories
INC			:= -I ./include -I ./libft

# Library file and directory
LIBFT		 = $(LIBFT_DIR)/libft.a
LIBFT_DIR	:= ./libft

# Build directory and object files
BUILD_DIR	:= .build
OBJS		:= $(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))

# Compiler settings
CC			:= clang
CFLAGS		:= -Wall -Wextra -Werror

# Build all
all: $(NAME)

# Build object files from source files
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(BUILD_DIR)
	@$(info creating .build directory)
	$(CC) $(CFLAGS) -MMD -MP $(INC) -c $< -o $@

# Build the final library
$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $@
	ar -rcs $(NAME) $(OBJS)

# Build the required library
$(LIBFT):
	make -C $(LIBFT_DIR)

# Clean object files
clean:
	rm -f $(OBJS) $(OBJS:.o=.d)
	rm -rf $(BUILD_DIR)
	make -C $(LIBFT_DIR) clean

# Clean all generated files
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

# Clean and build all
re: fclean all

# Phony targets
.PHONY: all clean fclean re
# .SILENT: all