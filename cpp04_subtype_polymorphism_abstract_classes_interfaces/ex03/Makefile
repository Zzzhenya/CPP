NAME = materia

SRC =  main.cpp AMateria.cpp

HEADER = AMateria.hpp

OBJ = $(SRC:.cpp=.o)

CXX = g++

CPPFLAGS = -Wall -Wextra -Werror -g -std=c++98 -Wshadow

all: $(NAME)

%.o: %.cpp Makefile $(HEADER)
	$(CXX) $(CPPFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean 
	rm -rf $(NAME)

re: fclean all

leaks: all
	valgrind ./(NAME)

.PHONY: all clean fclean re