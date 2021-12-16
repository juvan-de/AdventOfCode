# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: julesvanderhoek <julesvanderhoek@studen      +#+                      #
#                                                    +#+                       #
#    Created: 2021/02/18 15:01:24 by julesvander   #+#    #+#                  #
#    Updated: 2021/12/16 16:26:12 by juvan-de      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= 	d16e0

SOURCES		=	ex00.cpp \
				packet.cpp

OBJECTS 	=	${SOURCES:%.cpp=%.o}

FLAGS 		=	-Wall -Wextra -Werror -std=c++11
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
