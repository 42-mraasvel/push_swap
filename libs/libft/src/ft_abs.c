/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_abs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/17 12:26:54 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/16 23:28:45 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_double.h"

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

double	ft_fabs(double x)
{
	t_double	d;

	d.value = x;
	d.bits.sign = 0;
	return (d.value);
}

long long	ft_absll(long long l)
{
	if (l < 0)
		return (-l);
	return (l);
}
