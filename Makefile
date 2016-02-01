# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/29 14:39:00 by pdelefos          #+#    #+#              #
#    Updated: 2016/01/31 18:34:34 by pdelefos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_PATH = src
SRC_NAME = main.c \
		   parsing.c

OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:.c=.o)

PATH_INC = includes
PATH_LIBFT = libft/includes
LIBFT = libft/libft.a
MINILIBX = -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit

CC = clang
CFLAGS = -Wall -Werror -Wextra

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
INC = $(addprefix -I,$(PATH_INC) $(PATH_LIBFT))

NO_COLOR = \x1b[0m
GREEN = \x1b[32;01m
RED = \x1b[31;01m
BLUE = \x1b[34;01m
MAGENTA = \x1b[35;01m

all: title makelib $(NAME) end

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(INC) $(LIBFT) $(MINILIBX) $(OBJ) -o $(NAME) 
	@echo "$(RED)CC >>$(NO_COLOR) $(CFLAGS) libft minilibx $(RED)>>$(NO_COLOR) \
	$(OBJ_PATH) $(RED)>>$(NO_COLOR) $(NAME)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	@echo "$(GREEN)CC$(NO_COLOR) $(MAGENTA)>>$(NO_COLOR) $< $(MAGENTA)>>$(NO_COLOR) $@"

makelib:
	@make -C libft

clean:
	@rm -f $(OBJ)
	@echo "$(RED)RM >>$(NO_COLOR) $(OBJ_PATH)"
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)RM >>$(NO_COLOR) $(NAME)"

gfclean: fclean
	make fclean -C libft

re: fclean all

title:
	@echo "$(BLUE)   ▄████████ ████████▄     ▄████████ $(NO_COLOR)"
	@echo "$(BLUE)  ███    ███ ███   ▀███   ███    ███ $(NO_COLOR)"
	@echo "$(BLUE)  ███    █▀  ███    ███   ███    █▀  $(NO_COLOR)"
	@echo "$(BLUE) ▄███▄▄▄     ███    ███  ▄███▄▄▄     $(NO_COLOR)"
	@echo "$(BLUE)▀▀███▀▀▀     ███    ███ ▀▀███▀▀▀     $(NO_COLOR)"
	@echo "$(BLUE)  ███        ███    ███   ███        $(NO_COLOR)"
	@echo "$(BLUE)  ███        ███   ▄███   ███        $(NO_COLOR)"
	@echo "$(BLUE)  ███        ████████▀    ███        $(NO_COLOR)"

end:
	@echo "$(BLUE)-------------------------------------$(NO_COLOR)"
norme:
	norminette $(SRC)
	norminette $(PATH_INC)/fdf.h

.PHONY: all lib clean fclean gfclean re norme makelib title end
