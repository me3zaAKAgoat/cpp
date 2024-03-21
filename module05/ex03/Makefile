CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = exec

HEADERS = AForm.hpp\
Bureaucrat.hpp\
Intern.hpp\
PresidentialPardonForm.hpp\
RobotomyRequestForm.hpp\
ShrubberyCreationForm.hpp
SRCS = AForm.cpp\
Bureaucrat.cpp\
Intern.cpp\
PresidentialPardonForm.cpp\
RobotomyRequestForm.cpp\
ShrubberyCreationForm.cpp\
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
