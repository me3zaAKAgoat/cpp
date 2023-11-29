#!/bin/bash

rm Makefile
touch Makefile

echo -n 'CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = exec

HEADERS = ' >> Makefile 
ls *.hpp | awk 'NR > 1 { printf "\\\n" } { printf "%s", $0 } END { if (NR > 0) printf "\n" }' >> Makefile
echo "" >> Makefile

echo -n 'SRCS = ' >> Makefile
ls *.cpp | awk 'NR > 1 { printf "\\\n" } { printf "%s", $0 } END { if (NR > 0) printf "\n" }' >> Makefile

echo "" >> Makefile

echo 'OBJECTS = $(SRCS:.cpp=.o)

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

.PHONY : fclean re clean all' >> Makefile
