# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/19 12:49:48 by jschwabe          #+#    #+#              #
#    Updated: 2023/04/25 20:03:49 by jschwabe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = libftprintf.a
SRCS = ft_printf.c formatters.c put_utils.c
CFLAGS = -Wall -Wextra -Werror -g
DEPS = ft_printf.h
LIBFT_SRC = libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c libft/ft_itoa.c libft/ft_lstadd_back.c libft/ft_lstadd_front.c libft/ft_lstclear.c libft/ft_lstdelone.c libft/ft_lstiter.c libft/ft_lstlast.c libft/ft_lstmap.c libft/ft_lstnew.c libft/ft_lstsize.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_striteri.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c
LIBFT = libft/libft.a
OBJS = $(SRCS:.c=.o)
LIBFT_OBJ = $(LIBFT_SRC:.c=.o)
TESTFILES = main.c
# INC = -I includes/42libft
# LIB = ./includes/42libft/libft.a

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	make -C libft
	cp $(LIBFT) $@
	ar -rcs $(NAME) $(OBJS)
all: $(NAME)
# $(OBJS): %.o:%.c
# 	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# ./includes/42libft:
# 	make -C $(INC)
clean:
	rm -f $(OBJS)
	make clean -C libft
fclean: clean
	rm -f $(NAME)
	make fclean -C libft

tclean: clean
	rm -f $(TESTFILES:.c=.o)
	rm -f ./a.out

test: all
	$(CC) $(CFLAGS) $(NAME) $(TESTFILES) -fsanitize=address && ./a.out

re: fclean all
.PHONY: all clean fclean re

# -include $(DEPS)