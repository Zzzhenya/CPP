# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/06 01:17:00 by sde-silv          #+#    #+#              #
#    Updated: 2025/05/07 18:13:25 by sde-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serializer

SRC =  main.cpp Serializer.cpp Data.cpp

HEADER = Serializer.hpp Data.hpp

OBJ = $(SRC:.cpp=.o)

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98 -pedantic-errors #-Wshadow

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
