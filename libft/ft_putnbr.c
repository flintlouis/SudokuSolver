/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 16:58:21 by fhignett      #+#    #+#                 */
/*   Updated: 2019/04/03 17:34:39 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr(long long n)
{
	unsigned long long nb;

	if (n < 0)
	{
		write(1, "-", 1);
		nb = ABS(n);
	}
	else
		nb = n;
	if (nb < 10)
		ft_putchar(nb + 48);
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}
