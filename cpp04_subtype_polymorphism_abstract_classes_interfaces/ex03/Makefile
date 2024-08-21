# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/19 21:05:18 by sde-silv          #+#    #+#              #
#    Updated: 2024/08/21 19:50:49 by sde-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = materia

SRC =  main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp

HEADER = AMateria.hpp Ice.hpp Cure.hpp ICharacter.hpp Character.hpp

OBJ = $(SRC:.cpp=.o)

CXX = g++

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
	valgrind ./$(NAME)

.PHONY: all clean fclean re