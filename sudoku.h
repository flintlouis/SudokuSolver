/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sudoku.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/13 16:06:57 by fhignett       #+#    #+#                */
/*   Updated: 2019/04/16 19:13:18 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

int		solver(char **sud, int j, int i);
int		checker(char **sud, int j, int i, char n);
void	print_sudoku(char **sud);

#endif
