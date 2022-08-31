NAME = identification
CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f
SRCS = ./Identify.cpp ./Base.cpp ./A.cpp ./B.cpp ./C.cpp ./main.cpp
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

re: fclean all