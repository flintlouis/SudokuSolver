/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/16 14:39:06 by fhignett       #+#    #+#                */
/*   Updated: 2019/04/16 19:05:10 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

static int	check_hor(char **sud, int j, int i, char n)
{	
	for (int x = 0; x < 9; x++)
	{
		if (x != i && sud[j][x] == n)
			return (0);
	}
	return (1);
}

static int	check_ver(char **sud, int j, int i, char n)
{
	for (int y = 0; y < 9; y++)
	{
		if (y != j && sud[y][i] == n)
			return (0);
	}
	return (1);
}

static int	check_sqr(char **sud, int j, int i, char n)
{
	int y;
	int x;
	int xmax;
	int ymax;

	y = j - (j % 3);
	x = i - (i % 3);
	xmax = x + 3;
	ymax = y + 3;
	while (y < ymax)
	{
		while (x < xmax)
		{
			if ((i != x || j != y) && sud[y][x] == n)
				return (0);
			x++;
		}
		x -= 3;
		y++;
	}
	return (1);
}

int		checker(char **sud, int j, int i, char n)
{
	if (!check_hor(sud, j, i, n))
		return (0);
	if (!check_ver(sud, j, i, n))
		return (0);
	if (!check_sqr(sud, j, i, n))
		return (0);
	return (1);
}