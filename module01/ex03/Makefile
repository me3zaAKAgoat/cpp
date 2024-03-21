CC = c++
CFLAGS = -g -std=c++98 -Wall -Wextra -Werror 
NAME = weapon

HEADERS = HumanA.hpp HumanB.hpp Weapon.hpp
SRCS = HumanA.cpp HumanB.cpp Weapon.cpp main.cpp
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