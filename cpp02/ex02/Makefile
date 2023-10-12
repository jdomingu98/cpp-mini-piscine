NAME	= fixedPoints02
CFLAGS	= -Wall -Werror -Wextra -std=c++98
SRCS	= main.cpp Fixed.cpp
OBJS	= $(SRCS:.cpp=.o)

all:	$(NAME)

%.o:	%.cpp
	c++ $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	c++ $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: 	fclean all

.PHONY: all clean fclean re