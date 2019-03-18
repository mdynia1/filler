#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdynia <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/28 16:08:29 by mdynia            #+#    #+#              #
#    Updated: 2018/07/28 16:08:31 by mdynia           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =			mdynia.visualizer
FLAGS =			-Wall -Wextra -Werror

SRC_FILES =		main_visualizer.c \
				call_for_data.c \
				flags_dealer.c \
				ft_colors.c \
				visual_part.c

OBJ_FILES =		$(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	make -C ../libft
	gcc -o $(NAME) $(FLAGS) $(OBJ_FILES) ../libft/libft.a -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	
%.o : %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	make clean -C ../libft
	rm -f $(OBJ_FILES)

fclean:
	make fclean -C ../libft
	rm -f $(OBJ_FILES)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
