# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: julesvanderhoek <julesvanderhoek@studen      +#+                      #
#                                                    +#+                       #
#    Created: 2021/02/06 02:09:11 by julesvander   #+#    #+#                  #
#    Updated: 2021/12/13 14:56:52 by julesvander   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME 		= 	ex01

SOURCES		= 	day3_2.cpp

OBJECTS 	=	${SOURCES:%.cpp=%.o}

FLAGS 		=	-Wall -Wextra -Werror -std=c++98
COMPILE		=	clang++


GREEN 		= 	\033[38;5;46m
WHITE 		= 	\033[38;5;15m
GREY 		= 	\033[38;5;8m
ORANGE 		= 	\033[38;5;202m
RED 		= 	\033[38;5;160m

all: $(NAME)

%.o: %.cpp
	@echo "$(GREY)Compiling...				$(WHITE)$<"
	@$(COMPILE) -c $(SOURCES)

$(NAME): $(OBJECTS)
	@$(COMPILE) $(FLAGS) $(OBJECTS) -o $(NAME)
	@echo "$(GREEN)Use exe - $(NAME)"

clean:
	@echo "$(RED)Deleting objectfiles"
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@echo "$(RED)Deleting executable"
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
