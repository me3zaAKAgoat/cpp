CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = exec

HEADERS = ICharacter.hpp MateriaSource.hpp AMateria.hpp Character.hpp Cure.hpp IMateriaSource.hpp Ice.hpp

SRCS = AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp main.cpp
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
