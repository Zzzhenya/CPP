# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/19 21:05:18 by sde-silv          #+#    #+#              #
#    Updated: 2024/08/26 15:24:09 by sde-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = materia

SRC =  main.cpp AMateria.cpp \
		Ice.cpp Cure.cpp \
		Character.cpp MateriaSource.cpp

HEADER = AMateria.hpp Ice.hpp \
			Cure.hpp ICharacter.hpp \
			Character.hpp IMateriaSource.hpp \
			MateriaSource.hpp

OBJ = $(SRC:.cpp=.o)

CXX = clang++

CPPFLAGS = -Wall -Wextra -Werror -g -std=c++98 -Wshadow

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
	valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re