# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obensarj <obensarj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/31 17:13:44 by obensarj          #+#    #+#              #
#    Updated: 2024/11/21 23:03:21 by obensarj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_memset.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_bzero.c \
                ft_isalnum.c ft_isprint.c ft_toupper.c ft_tolower.c \
                 ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_strlen.c \
                 ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_isascii.c \
                 ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
                 ft_memmove.c ft_strdup.c ft_itoa.c ft_substr.c ft_strjoin.c \
                 ft_strtrim.c ft_split.c ft_strmapi.c ft_striteri.c \
                 ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \

OBJ = $(SRC:.c=.o)

CFALGS =  -Wall -Wextra -Werror

CC = cc

INCLUDE = libft.h

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

all: $(NAME)

%.o:%.c $(INCLUDE)
	$(CC) $(CFALGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean