NAME	= brainIdeas
CFLAGS	= -Wall -Werror -Wextra -std=c++98
SRCS	= main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
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