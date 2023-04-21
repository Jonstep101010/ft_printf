# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    $(MAKE)file                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/19 12:49:48 by jschwabe          #+#    #+#              #
#    Updated: 2023/04/20 13:53:08 by jschwabe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = libftprintf.a
SRCS = ft_printf.c $(wildcard srcs/*.c)
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
INC = -I libft

all: $(NAME)

$(NAME): $(OBJS) ./libft/libft.a
	mv libft/libft.a $@
	ar rcs $(NAME) $(OBJS)
$(OBJS): %.o:%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

./libft/libft.a:
	$(MAKE) -C libft
clean:
	$(MAKE) clean -C libft
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)
	# $(MAKE) fclean -C libft

re: fclean all
.PHONY: all clean fclean re