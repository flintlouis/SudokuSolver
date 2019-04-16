/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/15 18:31:14 by fhignett       #+#    #+#                */
/*   Updated: 2019/04/16 18:58:31 by fhignett      ########   odam.nl         */
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

int	solver(char **sud, int j, int i)
{
	char n = '0';
	int check = 0;
	
	if (j == 9)
		return (1);
	if (ft_isdigit(sud[j][i]))
	{
		get_index(&j, &i);
		solver(sud, j, i);
	}
	while (!check)
	{
		n++;
		if (n > '9')
			return (0);
		sud[j][i] = n;
		if ((check = checker(sud, j, i)))
		{
			get_index(&j, &i);
			if (!solver(sud, j, i))
				continue ;
		}
	}
	return (1);
}