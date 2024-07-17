# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-silv <sde-silv@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/17 16:26:18 by sde-silv          #+#    #+#              #
#    Updated: 2024/07/17 16:26:21 by sde-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = brains

CC = c++

CPPFLAGS = -Wall -Wextra -Werror -g -std=c++98 #-fsanitize=address

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp 
	$(CC) $(CPPFLAGS) -c -o $@ $<

$(NAME): $(OBJ) Makefile
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
