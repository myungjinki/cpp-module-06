NAME =	identify
FLAGS =	-Wall -Wextra -Werror
HEADER = -I. 
CC =	clang++
SRCS =	main.cpp Base.cpp 
OBJS =	$(SRCS:.cpp=.o)

all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(HEADER) $^ -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) $(HEADER) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
