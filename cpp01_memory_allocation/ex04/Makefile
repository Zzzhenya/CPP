NAME	=	ex04

SRC		=	main.cpp

OBJ		= 	$(SRC:.cpp=.o)

CXX		=	c++

#HEADER	=	

CPPFLAGS=	-Wall -Wextra -Werror -g -std=c++98

all: $(NAME)

%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c -o $@ $<

$(NAME): $(OBJ) Makefile #$(HEADER)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

leaks: $(NAME)
	valgrind --track-fds=yes ./$(NAME) test_files/one hello world

.PHONY: all clean fclean re leaks	