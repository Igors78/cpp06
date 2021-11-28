# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 22:31:17 by ioleinik          #+#    #+#              #
#    Updated: 2021/11/28 15:13:43 by ioleinik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX			= clang++
CXXFLAGS	= -Wall -Wextra -Werror -I.

RM			= rm -f

NAME		= serialize

SRC			= main.cpp

INC			= Data.hpp

OBJ			= ${SRC:.cpp=.o}

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)
			@echo "[./serialize] to run"

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re