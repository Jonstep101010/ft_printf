# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/19 12:49:48 by jschwabe          #+#    #+#              #
#    Updated: 2023/04/27 15:19:47 by jschwabe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
SRCS = ft_printf.c formatters.c put_utils.c

DEPS = ft_printf.h
LIBFT = libft/libft.a
OBJS = $(SRCS:.c=.o)
TESTFILES = main.c

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

re: fclean all
.PHONY: all clean fclean re

# -include $(DEPS)