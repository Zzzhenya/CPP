# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-silv <sde-silv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/17 14:51:19 by sde-silv          #+#    #+#              #
#    Updated: 2024/07/17 15:11:02 by sde-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombiezzz

CC = c++

CPPFLAGS = -Wall -Wextra -Werror -g -std=c++98 # -Wuninitialized

SRC = Zombie.cpp newZombie.cpp main.cpp randomChump.cpp

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
