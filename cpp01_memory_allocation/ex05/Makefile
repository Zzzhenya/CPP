NAME	=	ex05

SRC		=	main.cpp Harl.cpp

OBJ		= 	$(SRC:.cpp=.o)

CXX		=	c++

HEADER	=	Harl.hpp	

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
	valgrind --track-fds=yes ./$(NAME)

.PHONY: all clean fclean re leaks	