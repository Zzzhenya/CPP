# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/06 01:17:00 by sde-silv          #+#    #+#              #
#    Updated: 2025/05/27 21:12:25 by sde-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = base

DBGNAME = dbg_base

SRC =  main.cpp Base.cpp A.cpp B.cpp C.cpp X.cpp

HEADER = Base.hpp A.hpp B.hpp C.hpp X.hpp

OBJ = $(SRC:.cpp=.o)

DBGOBJ = $(SRC:.cpp=.dbg.o)

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98 -pedantic-errors #-Wshadow

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
