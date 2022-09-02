# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/25 17:42:24 by yechoi            #+#    #+#              #
#    Updated: 2020/11/25 17:42:24 by yechoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	main.cpp

OBJS		=	$(SRCS:.cpp=.o)

CC			=	clang++

FLAG		= 	-Wall -Wextra -Werror

INCLUDES	= 	-I.

NAME		=	convert

all			: $(NAME)

$(NAME)		: $(OBJS)
		$(CC) $(FLAG) $(OBJS) -o $(NAME) $(INCLUDES)

clean		:
		rm -rf $(OBJS)

fclean		: clean
		rm -rf $(NAME)

re			: fclean all

.PHONY 		: all clean fclean re