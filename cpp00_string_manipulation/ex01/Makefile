NAME = phonebook

CXX = c++

CPPFLAGS = -Wall -Wextra -Werror -g -std=c++98

SRC = main.cpp PhoneBook.cpp Contact.cpp PhoneBookSearch.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c -o $@ $<

$(NAME): $(OBJ) Makefile
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
