# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/12 17:26:07 by sde-silv          #+#    #+#              #
#    Updated: 2024/08/12 17:37:49 by sde-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = animals

SRC =  main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp\
		Brain.cpp

HEADER = Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp \
			Brain.hpp

OBJ = $(SRC:.cpp=.o)

CXX = c++

CPPFLAGS = -Wall -Wextra -Werror -g -std=c++98

all: $(NAME)

%.o: %.cpp Makefile $(HEADER)
	$(CXX) $(CPPFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean 
	rm -rf $(NAME)

re: fclean all

leaks: all
	valgrind ./(NAME)

.PHONY: all clean fclean re