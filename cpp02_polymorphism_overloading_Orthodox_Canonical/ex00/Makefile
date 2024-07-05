NAME	=	ex00

SRC		=	main.cpp Fixed.cpp

OBJ		= 	$(SRC:.cpp=.o)

CXX		=	clang++

HEADER	=	Fixed.hpp	

CPPFLAGS=	-Wall -Wextra -Werror -g -std=c++98

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

leaks: $(NAME)
	valgrind ./$(NAME) #--track-fds=yes

.PHONY: all clean fclean re leaks	