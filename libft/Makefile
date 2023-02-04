# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pboonpro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#                                                                              #
#    Created: 2022/07/14 23:10:22 by pboonpro          #+#    #+#              #
#    Updated: 2022/07/14 23:15:10 by pboonpro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isalnum.c ft_itoa.c ft_memset.c ft_strchr.c ft_strlcpy.c ft_strrchr.c \
ft_isalpha.c  ft_memchr.c   ft_putchar_fd.c  ft_strdup.c    ft_strlen.c   ft_strtrim.c \
ft_atoi.c    ft_isascii.c  ft_memcmp.c   ft_putendl_fd.c  ft_striteri.c  ft_strmapi.c  ft_substr.c \
ft_bzero.c   ft_isdigit.c  ft_memcpy.c   ft_putnbr_fd.c   ft_strjoin.c   ft_strncmp.c \
ft_calloc.c  ft_isprint.c  ft_memmove.c  ft_putstr_fd.c   ft_strlcat.c   ft_strnstr.c 	ft_split.c \
ft_tolower.c ft_toupper.c \

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
ft_lstclear.c ft_lstiter.c ft_lstmap.c \

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:%.c=%.o)

BOBJS = $(BONUS:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.c
	gcc $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS) $(BOBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

bonus : $(BOBJS)
	ar rcs $(NAME) $(BOBJS)

.PHONY : all clean fclean re bonus
