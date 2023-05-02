# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/19 12:49:48 by jschwabe          #+#    #+#              #
#    Updated: 2023/05/02 21:26:15 by jschwabe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
SRCS = ft_printf.c put_utils.c

DEPS = ft_printf.h
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_DIR = libft
OBJS = $(SRCS:.c=.o)
SEE = @
# TESTFILES = main.c

all: $(NAME)
%.o: %.c $(DEPS)
	$(SEE)$(CC) $(CFLAGS) -c $< -o $@

libft:
	git clone -b ft_printf https://github.com/Jonstep101010/libft.git libft

$(NAME): $(OBJS)
	$(SEE)make -C libft
	$(SEE)cp $(LIBFT) $@
	$(SEE)ar -rcs $(NAME) $(OBJS)

clean:
	$(SEE)rm -f $(OBJS)
	$(SEE)make -C libft clean 
fclean: clean
	$(SEE)rm -f $(NAME)
	$(SEE)make -C libft fclean

# tclean: clean
# 	rm -f $(TESTFILES:.c=.o)
# 	rm -f ./a.out

# test: all
# 	$(CC) $(CFLAGS) $(NAME) $(TESTFILES) -fsanitize=address && ./a.out

norm: $(SRCS)
	$(shell norminette | grep Error)

libftrm:
	$(SEE)rm -rf $(LIBFT_DIR)
	$(SEE)mkdir -p $(LIBFT_DIR)
re: fclean all

# not associated with a file name
.PHONY: all clean fclean re