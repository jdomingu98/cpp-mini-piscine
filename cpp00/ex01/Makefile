
NAME	= contactList
CFLAGS	= -Wall -Werror -Wextra -std=c++98
SRCS	= PhoneBook.cpp Contact.cpp ContactList.cpp
OBJS	= $(SRCS.cpp=.o)

all:	$(NAME)

%.o:	%.cpp
	g++ $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	g++ $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: 	fclean all

.PHONY: all clean fclean re