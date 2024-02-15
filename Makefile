# Output name
NAME		:= libftprintf.a

# Source files
VPATH		:= src/
SRCS		:= ft_ltoa.c ft_vdprintf.c ft_printf.c put_utils.c

# Include directories
INC			:= -I ./include

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
$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

# Clean object files
clean:
	rm -f $(OBJS) $(OBJS:.o=.d)
	rm -rf $(BUILD_DIR)

# Clean all generated files
fclean: clean
	rm -f $(NAME)

# Clean and build all
re: fclean all

# Phony targets
.PHONY: all clean fclean re
# .SILENT: all