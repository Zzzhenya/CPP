NAME = brains

CC = clang++

CPPFLAGS = -Wall -Wextra -Werror -g -std=c++98 #-fsanitize=address

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp 
	$(CC) $(CPPFLAGS) -c -o $@ $<

$(NAME): $(OBJ) Makefile
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
