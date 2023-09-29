# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pboonpro <pboonpro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 11:48:54 by pboonpro          #+#    #+#              #
#    Updated: 2023/09/29 13:49:17 by pboonpro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = pipex_utils.c pipex.c #utils_lib.c

OBJ = $(SRC:%.c=%.o)

LIBFT = libft/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

all : $(NAME)

$(NAME) : $(OBJ)
	make -C ./libft
	$(CC) $(CFLAGS) $^ $(LIBFT) -o $@

clean :
	make clean -C libft
	rm -rf $(OBJ)

fclean : clean
	make fclean -C libft
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
