# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fhignett <fhignett@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/09 15:24:52 by fhignett       #+#    #+#                 #
#    Updated: 2019/04/16 19:13:02 by fhignett      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FILESC = *.c
FLAGS = -Wall -Wextra -Werror
LIBFT = libft.a
NAME = solver

all: $(NAME)

$(NAME):
	@echo "compiling..."
	@gcc -o $(NAME) $(FILESC) $(LIBFT) -I .
	@echo "done"

clean:
	@echo "cleaning..."

fclean: clean
	@echo "fcleaning..."
	@rm -f $(NAME)
	@rm -f $(EXECUTABLE)

re: fclean all
