# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/29 14:21:47 by mki               #+#    #+#              #
#    Updated: 2021/09/13 13:42:32 by mki              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	convert
CXX			=	clang++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g
RM			=	rm -rf
FILES		=	Convert\
				main

SRCS_DIR	=	./
SRCS		=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES))) 
OBJS		=	$(addprefix $(SRCS_DIR), $(addsuffix .o, $(FILES))) 

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
