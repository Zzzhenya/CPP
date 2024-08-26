# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/19 21:05:18 by sde-silv          #+#    #+#              #
#    Updated: 2024/08/26 22:57:07 by sde-silv         ###   ########.fr        #
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
			MateriaSource.hpp

DBGHEADER = $(HEADER) debug.hpp

OBJ = $(SRC:.cpp=.o)

DBGOBJ = $(SRC:.cpp=.dbg.o)

CXX = clang++

CPPFLAGS = -Wall -Wextra -Werror -g -std=c++98 -Wshadow

DBGCPPFLAGS = $(CPPFLAGS) -D_DEBUG

all: $(NAME)

%.o: %.cpp Makefile $(HEADER)
	$(CXX) $(CPPFLAGS) -c -o $@ $<

%.dbg.o: %.cpp Makefile $(DBGHEADER)
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

debug: $(DBGNAME)

leaks: all
	valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re debug