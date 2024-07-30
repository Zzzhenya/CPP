# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 17:53:02 by sde-silv          #+#    #+#              #
#    Updated: 2024/07/30 22:05:49 by sde-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ex02

SRC		=	main.cpp Fixed.cpp

OBJ		= 	$(SRC:.cpp=.o)

CXX		=	c++

HEADER	=	Fixed.hpp	

CPPFLAGS=	-Wall -Wextra -Werror -g -std=c++98

all: $(NAME)

%.o: %.cpp Makefile $(HEADER)
	$(CXX) $(CPPFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

leaks: $(NAME)
	valgrind ./$(NAME) #--track-fds=yes

.PHONY: all clean fclean re leaks	