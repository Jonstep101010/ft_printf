# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/19 12:49:48 by jschwabe          #+#    #+#              #
#    Updated: 2023/04/20 13:53:08 by jschwabe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = libftprintf.a
SRCS = ft_printf.c
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
INC = -I libft
LDFLAGS = -L./libft

all: $(NAME)

$(NAME): $(OBJS) ./libft/libft.a
	mv libft/libft.a $@
	ar rcs $(NAME) $(OBJS)
$(OBJS): %.o:%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

./libft/libft.a:
	make -C libft
clean:
	rm -f $(OBJS)
	make clean -C libft
fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all
.PHONY: all clean fclean re