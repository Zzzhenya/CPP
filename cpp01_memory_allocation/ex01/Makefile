# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-silv <sde-silv@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/17 16:08:59 by sde-silv          #+#    #+#              #
#    Updated: 2024/07/17 16:09:02 by sde-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = horde

CC = c++

CPPFLAGS = -Wall -Wextra -Werror -g -std=c++98 #-fsanitize=address

SRC = Zombie.cpp main.cpp zombieHorde.cpp

INCLUDE = Zombie.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp 
	$(CC) $(CPPFLAGS) -c -o $@ $<

$(NAME): $(OBJ) Makefile $(INCLUDE)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
