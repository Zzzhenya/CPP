# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/13 23:17:41 by sde-silv          #+#    #+#              #
#    Updated: 2025/01/30 15:49:59 by sde-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = iter

SRC = main.cpp

HEADER = iter.hpp

OBJ = $(SRC:.cpp=.o)

CXX = clang++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Wpedantic

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
