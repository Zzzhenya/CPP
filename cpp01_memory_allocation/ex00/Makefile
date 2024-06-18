NAME = zombiezzz

CC = clang++

CPPFLAGS = -Wall -Wextra -Werror -g -std=c++98

SRC = Zombie.cpp newZombie.cpp main.cpp randomChump.cpp

INCLUDE = Zombie.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp 
	$(CC) $(CPPFLAGS) -c -o $@ $<

$(NAME): $(OBJ) Makefile $(INCLUDE)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
