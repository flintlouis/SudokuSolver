/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/13 16:05:02 by fhignett       #+#    #+#                */
/*   Updated: 2019/06/20 17:29:46 by fhignett      ########   odam.nl         */
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

void print_sudoku(char **sud)
{
	int i = 0;
	int j = 0;
	while (j < 9)
	{
		ft_putchar(' ');
		while (i < 11)
		{
			ft_putchar(sud[j][i]);
			ft_putchar(' ');
			if (i == 2 || i == 5)
			{
				ft_putchar('|');
				ft_putchar(' ');
			}
			i++;
		}
		ft_putchar('\n');
		i = 0;
		if (j == 2 || j == 5)
			ft_putendl(" ------+-------+------");
		j++;
	}
}

static void solve_sudoku(char *file)
{
	char **sud;

	sud = get_sudoku(file);
	system("clear");
	print_sudoku(sud);
	getchar();
	if (solver(sud, 0, 0))
	{
		system("clear");
		print_sudoku(sud);
	}
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
