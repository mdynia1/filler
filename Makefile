#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdynia <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/22 20:50:17 by mdynia            #+#    #+#              #
#    Updated: 2018/07/22 20:50:19 by mdynia           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =			mdynia.filler
FLAGS =			-Wall -Wextra -Werror

SRC_FILES =		strategy.c \
				data_gather.c \
				main.c

OBJ_FILES =		$(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	make -C libft
	gcc -o $(NAME) $(OBJ_FILES) -L libft -lft

%.o : %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	make clean -C libft
	rm -f $(OBJ_FILES)

fclean:
	make fclean -C libft
	rm -f $(OBJ_FILES)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
