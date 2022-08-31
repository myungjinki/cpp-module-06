NAME = convert
CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f
SRCS = ./Convert.cpp ./main.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY : bonus all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all
