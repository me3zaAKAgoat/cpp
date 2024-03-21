CC = c++
CFLAGS = -g -std=c++98 -Wall -Wextra -Werror 
NAME = DT

HEADERS = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp
SRCS = ClapTrap.cpp main.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
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