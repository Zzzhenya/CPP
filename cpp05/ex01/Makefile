# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/04 01:32:40 by sde-silv          #+#    #+#              #
#    Updated: 2024/11/13 22:15:35 by sde-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = form

DBGNAME = dbg_form

SRC =  main.cpp Bureaucrat.cpp Form.cpp

HEADER = Bureaucrat.hpp Form.hpp

OBJ = $(SRC:.cpp=.o)

DBGOBJ = $(SRC:.cpp=.dbg.o)

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98 #-Wshadow

DBGCXXFLAGS = $(CXXFLAGS) -D_DEBUG

all: $(NAME) $(DBGNAME)

%.o: %.cpp Makefile $(HEADER)
	$(CXX) $(CXXFLAGS) -c -o $@ $<	

%.dbg.o: %.cpp Makefile $(HEADER)
	$(CXX) $(DBGCXXFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(DBGNAME): $(DBGOBJ)
	$(CXX) $(DBGCXXFLAGS) $(DBGOBJ) -o $(DBGNAME)

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
