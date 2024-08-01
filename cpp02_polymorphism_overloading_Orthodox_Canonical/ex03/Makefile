NAME	=	ex03

DBGNAME =	dbg_ex03

SRC		=	main.cpp Fixed.cpp Point.cpp bsp.cpp

OBJ		= 	$(SRC:.cpp=.o)

DBGOBJ	= 	$(SRC:.cpp=.dbg.o)

CXX		=	c++

HEADER	=	Fixed.hpp Point.hpp

CPPFLAGS=	-Wall -Wextra -Werror -g -std=c++98

DBGCPPFLAGS = $(CPPFLAGS) -D_DEBUG

all: $(NAME)

%.o: %.cpp Makefile $(HEADER)
	$(CXX) $(CPPFLAGS) -c -o $@ $<

%.dbg.o: %.cpp Makefile $(HEADER)
	$(CXX) $(DBGCPPFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

$(DBGNAME): $(DBGOBJ)
	$(CXX) $(DBGCPPFLAGS) $(DBGOBJ) -o $(DBGNAME)

clean:
	rm -rf $(OBJ)
	rm -rf $(DBGOBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(DBGNAME)

re: fclean all

leaks: $(NAME)
	valgrind ./$(NAME) #--track-fds=yes

debug: $(DBGNAME)

.PHONY: all clean fclean re leaks debug