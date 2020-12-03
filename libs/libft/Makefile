# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bditte <bditte@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/21 14:38:26 by bditte            #+#    #+#              #
#    Updated: 2020/11/21 16:54:56 by bditte           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS=-Wall -Wextra -Werror

NAME =libft.a

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_putstr.c ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

OBJ = $(SRC:.c=.o)

HEADERS= -I include/

BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUS_OBJ=$(BONUS_SRC:.c=.o)

all: $(NAME)

%.o: %.c 
	$(CC) $(HEADERS)  $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

bonus:
	@make all OBJ="$(OBJ) $(BONUS_OBJ)"

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

