
NAME = megaphone
CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++98
SRCS = 	megaphone.cpp
OBJS = (SRCS.cpp=.o)

all = $(NAME)

%.o:		%.cpp
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME) = 	$(OBJS)
			$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
			rm -rf $(OBJS)

fclean: 	clean
			rm -f $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re