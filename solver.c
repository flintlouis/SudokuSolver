/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/15 18:31:14 by fhignett       #+#    #+#                */
/*   Updated: 2019/12/04 14:50:09 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

static void get_index(int *j, int *i)
{
	if (*i < 8)
		*i += 1;
	else
	{
		*i = 0;
		*j += 1;
	}
}

static void go_back_index(int *j, int *i)
{
	if (*i == 0)
	{
		*i = 8;
		*j -= 1;
	}
	else
		*i -= 1;
}

static void backtracking(char **sud)
{
	system("clear");
	print_sudoku(sud);
	// sleep(1);
}

int	solver(char **sud, int j, int i)
{
	char nbr = '1';

	if (j == 9)
		return (1);
	if (ft_isdigit(sud[j][i]))
	{
		get_index(&j, &i);
		return (solver(sud, j, i));
	}
	backtracking(sud); /* <------- to show the backtracking */
	while (nbr <= '9')
	{
		if (checker(sud, j, i, nbr))
		{
			sud[j][i] = nbr;
			get_index(&j, &i);
			if (solver(sud, j, i))
				return (1);
			else
			{
				go_back_index(&j, &i);
				sud[j][i] = '.';
			}
		}
		nbr += 1;
	}
	return (0);
}
