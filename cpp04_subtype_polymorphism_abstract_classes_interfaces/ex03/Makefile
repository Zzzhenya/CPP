# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/19 21:05:18 by sde-silv          #+#    #+#              #
#    Updated: 2024/08/27 20:20:42 by sde-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = materia

DBGNAME = dbg_materia

SRC =  main.cpp AMateria.cpp \
		Ice.cpp Cure.cpp \
		Character.cpp MateriaSource.cpp

HEADER = AMateria.hpp Ice.hpp \
			Cure.hpp ICharacter.hpp \
			Character.hpp IMateriaSource.hpp \
			MateriaSource.hpp \
			debug.hpp

OBJ = $(SRC:.cpp=.o)

DBGOBJ = $(SRC:.cpp=.dbg.o)

CXX = c++

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