# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/04 01:32:40 by sde-silv          #+#    #+#              #
#    Updated: 2024/09/05 16:08:18 by sde-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = form

DBGNAME = dbg_form

SRC =  main.cpp Bureaucrat.cpp Form.cpp

HEADER = Bureaucrat.hpp Form.hpp

OBJ = $(SRC:.cpp=.o)

DBGOBJ = $(SRC:.cpp=.dbg.o)

CXX = clang++

CPPFLAGS = -Wall -Wextra -Werror -g -std=c++98 #-Wshadow

DBGCPPFLAGS = $(CPPFLAGS) -D_DEBUG

all: $(NAME) $(DBGNAME)

%.o: %.cpp Makefile $(HEADER)
	$(CXX) $(CPPFLAGS) -c -o $@ $<

%.dbg.o: %.cpp Makefile $(HEADER)
	$(CXX) $(DBGCPPFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

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
