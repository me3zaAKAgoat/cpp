CC = c++
CFLAGS = -g -std=c++98 -Wall -Wextra -Werror 
NAME = phonebook 

HEADERS = PhoneBook.hpp Contact.hpp
SRCS = main.cpp PhoneBook.cpp Contact.cpp
OBJECTS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

%.o : %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -I./ -c $< -o $@

clean :
	rm -rf $(OBJECTS)

fclean :
	rm -rf $(OBJECTS)
	rm -rf $(NAME)

re : fclean all

.PHONY : fclean re clean all