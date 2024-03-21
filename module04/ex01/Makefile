CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = exec

HEADERS = Animal.hpp\
Brain.hpp\
Cat.hpp\
Dog.hpp\
WrongAnimal.hpp\
WrongCat.hpp
SRCS = Animal.cpp\
Brain.cpp\
Cat.cpp\
Dog.cpp\
WrongAnimal.cpp\
WrongCat.cpp\
main.cpp
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
