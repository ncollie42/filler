# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/12 10:10:25 by ncollie           #+#    #+#              #
#    Updated: 2018/12/08 17:24:12 by ncollie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FILES =	ft_isdigit.c ft_memset.c ft_strchr.c ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strlen.c ft_strncpy.c ft_tolower.c ft_toupper.c ft_strjoin.c ft_strsub.c ft_strcat.c ft_strdel.c ft_strnew.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_putstr_fd.c ft_putendl_fd.c ft_strmapi.c ft_putchar.c ft_putstr.c get_next_line.c b_printf.c ft_addchar.c ft_isalpha.c ft_isalnum.c ft_strncmp.c ft_strstr.c ft_strsplit.c ft_strndup.c ft_replace_word.c double_char_ptr_size.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strncat.c ft_strlcat.c ft_strrchr.c ft_strnstr.c ft_atoi.c ft_isascii.c ft_isprint.c ft_memdel.c ft_memalloc.c ft_strclr.c ft_strnequ.c ft_strequ.c ft_putnbr.c ft_strtrim.c ft_putchar_fd.c ft_putnbr_fd.c ft_putendl.c ft_striter.c ft_striteri.c ft_strmap.c ft_itoa.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c
OBJECTS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

%.o: %.c
	gcc -Wall -Werror -Wextra -I includes/ -c $< -o $@


clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)
re: fclean all

