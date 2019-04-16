/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_clamp.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 13:28:16 by fhignett       #+#    #+#                */
/*   Updated: 2019/03/27 13:28:32 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

float		ft_clamp(int min, int max, float z)
{
	if (z < min)
		return (min);
	else if (z > max)
		return (max);
	return (z);
}
