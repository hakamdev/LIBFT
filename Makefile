# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehakam <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/12 16:48:13 by ehakam            #+#    #+#              #
#    Updated: 2019/11/02 15:28:56 by ehakam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- Makefile -*-

NAME = libft.a
FLAGS = -Wall -Werror -Wextra
CC = gcc
SRC = ft_atoi.c	ft_isdigit.c ft_strlcat.c ft_strnstr.c ft_isalnum.c ft_isprint.c ft_strlcpy.c ft_strrchr.c ft_isalpha.c ft_memset.c ft_strlen.c ft_tolower.c ft_isascii.c ft_strchr.c ft_strncmp.c ft_toupper.c ft_memcpy.c ft_bzero.c ft_memccpy.c ft_memmove.c ft_memcmp.c ft_memchr.c ft_strdup.c ft_calloc.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_putnbr_fd.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_strmapi.c ft_split.c ft_itoa.c
BON = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c

all: $(NAME) 

$(NAME): $(SRC)
	@$(CC) $(SRC) -c $(FLAGS)
	@ar rc $(NAME) *.o

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME) *.a

re: fclean all

bonus: $(NAME) $(BON)
	@$(CC) $(BON) -c $(FLAGS)
	@ar rc $(NAME) *.o
