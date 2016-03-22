# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Mathiissss <marvin@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 1903/21/21 21:42:42 by rdidier           #+#    #+#              #
#    Updated: 2016/03/22 15:56:14 by rdidier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol

SRC		=	sources/main.c							\
			sources/image.c							\
			sources/complex.c						\
			sources/fractol.c						\
			sources/algo.c							\
			sources/color.c							\

OBJ		=	$(patsubst src/%.c,./%.o,$(SRC))

FLAG	=	-Wall -Werror -Wextra -framework OpenGL -framework AppKit

.SILENT:

$(NAME): $(OBJ)
	make -C libft/
	gcc $(FLAG) $(OBJ)  -L/usr/local/lib -lmlx -L libft/ -lft -o $(NAME)
	printf '\033[4m'
	printf '\033[32m[ ✔ ] %s\n\033[0m' "fractol is done !"
./%.o: src/%.c
	gcc $(FLAG) -c $< -o $@
	printf '\033[0m[ ✔ ] %s\n\033[0m' "$<"

clean:
	make -C libft/ clean
	/bin/rm -rf *.o
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean"

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean"

javel:
	clear

boom : javel fclean $(NAME) clean
	./fractol

re: fclean all

all: $(NAME)

.PHONY: clean fclean re all
