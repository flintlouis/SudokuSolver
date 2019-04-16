/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/13 16:05:02 by fhignett       #+#    #+#                */
/*   Updated: 2019/04/16 19:06:20 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

static char **get_sudoku(char *file)
{
	char **sud;
	int fd;
	int i;

	i = 0;
	if (!(fd = open(file, O_RDONLY)))
		exit(1);
	sud = (char**)ft_memalloc(sizeof(char*) * 9);
	while (i < 9)
	{
		if (!(sud[i] = (char*)ft_memalloc(sizeof(char) * 9)))
			exit(1);
		if (ft_get_next_line(fd, &sud[i]) == -1)
			exit(1);
		i++;
	}
	return (sud);
}

static void print_sudoku(char **sud)
{
	for (int d = 0; d < 9; d++)
		ft_putendl(sud[d]);
}

static void solve_sudoku(char *file)
{
	char **sud;

	sud = get_sudoku(file);
	if (solver(sud, 0, 0) == 1)
		print_sudoku(sud);
	else
		ft_putendl("Invalid Sudoku...");
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	else
		solve_sudoku(argv[1]);
	return (0);
}
