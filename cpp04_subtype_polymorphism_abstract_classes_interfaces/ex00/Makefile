NAME = animals

SRC =  main.cpp Animal.cpp

HEADER = Animal.hpp 

OBJ = $(SRC:.cpp=.o)

CXX = c++

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