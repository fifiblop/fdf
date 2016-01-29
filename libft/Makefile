# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 15:22:44 by pdelefos          #+#    #+#              #
#    Updated: 2016/01/29 14:32:44 by pdelefos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
LIB_NAME = $(NAME)

SRC_PATH = src
SRC_NAME = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
			ft_isdigit.c ft_islower.c ft_isprint.c ft_isupper.c ft_itoa.c \
			ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
			ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c \
			ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
			ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c \
			ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c \
			ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c \
			ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
			ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c \
			ft_strnstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
			ft_strstr.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
			ft_lstiter.c ft_lstmap.c ft_abs.c ft_strupcase.c ft_strlowcase.c \
			ft_lstsize.c ft_lst_pback.c ft_itoa_base.c get_next_line.c

OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:.c=.o)

INC_PATH = includes

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH)/)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(LIB_NAME) $(OBJ)
	ranlib $(LIB_NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean: 
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -fv $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)/libft.h

.PHONY: all clean fclean re norme
