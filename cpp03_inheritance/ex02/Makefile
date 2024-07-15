NAME = fragtrap

SRC = ClapTrap.cpp ScavTrap.cpp FragTrap.cpp main.cpp

HEADER = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp

OBJ = $(SRC:.cpp=.o)

CXX = clang++

CPPFLAGS = -Wall -Wextra -Werror -g -std=c++98

all: $(NAME)

%.o: %.cpp 
	$(CXX) $(CPPFLAGS) -c -o $@ $<

$(NAME): $(OBJ) Makefile $(HEADER)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean 
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re