# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/27 00:19:45 by sde-silv          #+#    #+#              #
#    Updated: 2025/08/19 21:19:32 by sde-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = PmergeMe

SRC = main.cpp PmergeMe.cpp

HEADER = PmergeMe.hpp

OBJ = $(SRC:.cpp=.o)

CXX = clang++ #-H

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic-errors -O3 #-Wpedantic

all: $(NAME)

%.o: %.cpp Makefile $(HEADER)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean 
	rm -rf $(NAME)

re: fclean all

leaks: all 
	valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re
