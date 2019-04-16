# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fhignett <fhignett@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/09 15:24:52 by fhignett       #+#    #+#                 #
#    Updated: 2019/04/13 16:53:38 by fhignett      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FILESC = *.c
FLAGS = -Wall -Wextra -Werror
LIBFT = -Llibft -lft
NAME = sudokusolver

all: $(NAME)

$(NAME):
	@echo "compiling..."
	@make -C libft
	@gcc -o $(NAME) $(FILESC) $(LIBFT) -I .
	@echo "done"

clean:
	@echo "cleaning..."
	@make clean -C libft

fclean: clean
	@echo "fcleaning..."
	@make fclean -C libft
	@rm -f $(NAME)
	@rm -f $(EXECUTABLE)

re: fclean all
