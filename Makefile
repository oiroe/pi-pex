# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pboonpro <pboonpro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 11:48:54 by pboonpro          #+#    #+#              #
#    Updated: 2023/02/04 11:54:01 by pboonpro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#dont use it yet!!!!

NAME = pipex

SRC = ft_printf.c c.c d.c p.c s.c x.c upperx.c u.c \

OBJ = $(SRC:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	ar rsc $(NAME) $(OBJ)

%.o : %.c
	gcc $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
