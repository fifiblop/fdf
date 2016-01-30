# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 15:22:44 by pdelefos          #+#    #+#              #
#    Updated: 2016/01/30 15:05:51 by pdelefos         ###   ########.fr        #
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
			ft_lstsize.c ft_lst_pback.c ft_itoa_base.c

OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:.c=.o)

INC_PATH = includes

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH)/)

NO_COLOR = \x1b[0m
GREEN = \x1b[32;01m
RED = \x1b[31;01m
BLUE = \x1b[34;01m
MAGENTA = \x1b[35;01m

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(LIB_NAME) $(OBJ)
	@echo "$(GREEN)AR RC$(NO_COLOR) $(MAGENTA)>>$(NO_COLOR) $(OBJ_PATH) $(MAGENTA)>>$(NO_COLOR) $(NAME)"
	@ranlib $(LIB_NAME)
	@echo "$(GREEN)RANLIB$(NO_COLOR) $(MAGENTA)>>$(NO_COLOR) $(LIB_NAME)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	@echo "$(GREEN)CC$(NO_COLOR) $(MAGENTA)>>$(NO_COLOR) $< $(MAGENTA)>>$(NO_COLOR) $@"

clean: 
	@rm -f $(OBJ)
	@echo "$(RED)RM >>$(NO_COLOR) $(OBJ_PATH)"
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)RM >>$(NO_COLOR) $(NAME)"

re: fclean all

norme:
	norminette $(SRC_NAME)
	norminette $(INC)libft.h

.PHONY: all clean fclean re norme
