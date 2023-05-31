# Output name
NAME	:= libft.a

# Compiler settings
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror

# Archiver
AR		:= ar -rcs

# File removal
RM		:= rm
RMFLAGS	:= -f

# Header files
DEPS	:= libft.h

# Source files
SRCS 	:= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_putchar.c ft_strnchr.c

B_SRCS	:= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c

# Object files
OBJS	:= $(SRCS:.c=.o)
B_OBJS	:= $(B_SRCS:.c=.o)

# Build all
all: $(NAME)

# Archive object files into the library
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# Bonus rule to include additional source files
bonus: $(B_OBJS) $(OBJS)
	$(AR) $(NAME) $(B_OBJS) $(OBJS)

# Compile source files (.c) into object files (.o)
.c.o: $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

# Include dependency files
-include $(OBJS:.o=.d)

# Clean up object files
clean:
	$(RM) $(RMFLAGS) $(OBJS) $(B_OBJS)

# Clean up all generated files
fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

# Clean up object files and test files
tclean: clean
	$(RM) $(RMFLAGS) a.out
	$(RM) $(RMFLAGS) $(TESTFILE:.c=.o)

# Build and run test file
test: $(NAME) $(TESTFILE:.c=.o)
	$(CC) $(CFLAGS) -o ./a.out $(TESTFILE:.c=.o) $(NAME)
	./a.out

# Clean and build all
re: fclean all

# Phony targets
.PHONY: all bonus clean fclean re
