# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/19 12:49:48 by jschwabe          #+#    #+#              #
#    Updated: 2023/05/02 20:59:31 by jschwabe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
SRCS = ft_printf.c put_utils.c

DEPS = ft_printf.h
LIBFT = libft/libft.a
LIBFT_DIR = libft
OBJS = $(SRCS:.c=.o)
# TESTFILES = main.c

all: $(NAME)
%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	git clone -b ft_printf https://github.com/Jonstep101010/libft.git libft

$(NAME): $(OBJS)
	make -C libft
	cp $(LIBFT) $@
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	make -C libft clean 
fclean: clean
	rm -f $(NAME)
	make -C libft fclean

# tclean: clean
# 	rm -f $(TESTFILES:.c=.o)
# 	rm -f ./a.out

# test: all
# 	$(CC) $(CFLAGS) $(NAME) $(TESTFILES) -fsanitize=address && ./a.out

libftrm:
	rm -rf $(LIBFT_DIR)
	mkdir -p $(LIBFT_DIR)
re: fclean all
.PHONY: all clean fclean re

# -include $(DEPS)