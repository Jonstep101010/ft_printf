# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschwabe <jonas.paul.schwabe@gmail.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/19 12:49:48 by jschwabe          #+#    #+#              #
#    Updated: 2023/04/29 11:41:46 by jschwabe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
SRCS = ft_printf.c formatters.c formatters_hex.c put_utils.c

DEPS = ft_printf.h
LIBFT = libft/libft.a
LIBFT_DIR = libft
OBJS = $(SRCS:.c=.o)
TESTFILES = main.c

$(LIBFT): $(LIBFT_DIR)
	git clone -b ft_printf https://github.com/Jonstep101010/libft.git libft
%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	make -C libft
	cp $(LIBFT) $@
	ar -rcs $(NAME) $(OBJS)
	# @ranlib $(NAME)
all: $(NAME)

clean:
	rm -f $(OBJS)
	make -C libft clean 
fclean: clean
	rm -f $(NAME)
	make -C libft fclean

tclean: clean
	rm -f $(TESTFILES:.c=.o)
	rm -f ./a.out

test: all
	$(CC) $(CFLAGS) $(NAME) $(TESTFILES) -fsanitize=address && ./a.out

libftrm:
	rm -rf $(LIBFT_DIR)
	mkdir -p $(LIBFT_DIR)
re: fclean all
.PHONY: all clean fclean re

# -include $(DEPS)