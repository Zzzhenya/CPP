# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/13 23:17:41 by sde-silv          #+#    #+#              #
#    Updated: 2025/04/02 14:44:16 by sde-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = array

NAME_TEST = test_array

SRC = main.cpp

SRC_TEST = main_07.cpp

HEADER = Array.hpp Array.tpp

OBJ = $(SRC:.cpp=.o)

OBJ_TEST = $(SRC_TEST:.cpp=.o)

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Wpedantic

all: $(NAME)

test: $(OBJ_TEST)
	$(CXX) $(CXXFLAGS) $(OBJ_TEST) -o $(NAME_TEST)

%.o: %.cpp Makefile $(HEADER)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_TEST)

fclean: clean 
	rm -rf $(NAME)
	rm -rf $(NAME_TEST)

re: fclean all

leaks: all 
	valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re tests
