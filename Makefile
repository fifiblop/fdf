# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/29 14:39:00 by pdelefos          #+#    #+#              #
#    Updated: 2016/03/13 13:15:28 by pdelefos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_PATH = src
SRC_NAME = main.c \
		   parse.c \
		   error.c \
		   keys.c \
		   calc.c \
		   draw.c \
		   grid.c \
		   set_image.c

OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:.c=.o)

PATH_INC = includes
PATH_LIBFT = libft/includes
LIBFT = libft/libft.a
PATH_MINILIBX = minilibx/
MINILIBX = minilibx/libmlx.a -lmlx -framework OpenGL -framework AppKit
#MINILIBX = -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit

CC = clang
CFLAGS = -Wall -Werror -Wextra

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
INC = $(addprefix -I,$(PATH_INC) $(PATH_LIBFT) $(PATH_MINILIBX))

NO_COLOR = \x1b[0m
GREEN = \x1b[32;01m
RED = \x1b[31;01m
BLUE = \x1b[34;01m
MAGENTA = \x1b[35;01m

all: title maklibft makminilibx $(NAME) end

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(INC) $(LIBFT) $(MINILIBX) $(OBJ) -o $(NAME) 
	@echo "$(GREEN)CC >>$(NO_COLOR) $(CFLAGS) libft minilibx $(GREEN)>>$(NO_COLOR) \
	$(OBJ_PATH) $(GREEN)>> $(NAME)$(NO_COLOR)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	@echo "$(GREEN)CC$(NO_COLOR) $(MAGENTA)>>$(NO_COLOR) $< $(MAGENTA)>>$(NO_COLOR) $@"

maklibft:
	@make -C libft
	@echo "$(BLUE)-------------------------------------$(NO_COLOR)"

makminilibx:
	@make -C minilibx
	@echo "$(BLUE)-------------------------------------$(NO_COLOR)"

clean:
	@rm -f $(OBJ)
	@echo "$(RED)RM >>$(NO_COLOR) $(OBJ_PATH)"
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)RM >>$(NO_COLOR) $(NAME)"

gfclean: fclean
	make fclean -C libft
	make clean -C minilibx

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
	@echo "$(BLUE)-------------------------------------$(NO_COLOR)"

end:
	@echo "$(BLUE)-------------------------------------$(NO_COLOR)"

norme:
	norminette $(SRC)
	norminette $(PATH_INC)/fdf.h

.PHONY: all lib clean fclean gfclean re norme makelib title end
