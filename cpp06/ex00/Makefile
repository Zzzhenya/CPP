# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/06 01:17:00 by sde-silv          #+#    #+#              #
#    Updated: 2024/09/12 14:51:26 by sde-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = converter

DBGNAME = dbg_converter

SRC =  main.cpp ScalarConverter.cpp

HEADER = ScalarConverter.hpp

OBJ = $(SRC:.cpp=.o)

DBGOBJ = $(SRC:.cpp=.dbg.o)

CXX = clang++

CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98 -ansi -pedantic-errors #-Wshadow

DBGCPPFLAGS = $(CXXFLAGS) -D_DEBUG

all: $(NAME) $(DBGNAME)

%.o: %.cpp Makefile $(HEADER)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.dbg.o: %.cpp Makefile $(HEADER)
	$(CXX) $(DBGCPPFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(DBGNAME): $(DBGOBJ)
	$(CXX) $(DBGCPPFLAGS) $(DBGOBJ) -o $(DBGNAME)

clean:
	rm -rf $(OBJ)
	rm -rf $(DBGOBJ)

fclean: clean 
	rm -rf $(NAME)
	rm -rf $(DBGNAME)

re: fclean all

leaks: all 
	valgrind --leak-check=full ./$(NAME)

debug: all
	valgrind --leak-check=full ./$(DBGNAME)

.PHONY: all clean fclean re debug
