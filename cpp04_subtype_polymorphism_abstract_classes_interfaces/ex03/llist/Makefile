# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/19 21:05:18 by sde-silv          #+#    #+#              #
#    Updated: 2024/08/22 22:49:30 by sde-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = llist

SRC =  main.cpp Node.cpp LinkedList.cpp ../AMateria.cpp ../Cure.cpp

HEADER = Node.hpp LinkedList.hpp ../AMateria.hpp ../Cure.hpp

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
	valgrind --leak-check=full -s ./$(NAME)

.PHONY: all clean fclean re