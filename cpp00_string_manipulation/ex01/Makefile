NAME = phonebook

CC = c++

CPPFLAGS = -Wall -Wextra -Werror -g -std=c++98

SRC = main.cpp PhoneBook.cpp Contact.cpp PhoneBookSearch.cpp

#INCLUDE = PhoneBook.hpp Contact.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

#%.o: %.cpp
#	$(CC) $(CPPFLAGS) -c -o $@ $<

$(NAME): $(OBJ) Makefile
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
