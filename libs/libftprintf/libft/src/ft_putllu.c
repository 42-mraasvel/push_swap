/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putllu.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 10:49:32 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/16 23:21:48 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static int	output_llu(unsigned long long nbr)
{
	char	c;

	if (nbr != 0)
	{
		if (output_llu(nbr / 10) == -1)
			return (-1);
		c = nbr % 10 + '0';
		if (write(1, &c, 1) == -1)
			return (-1);
	}
	return (0);
}

/*
** MAX: 18446744073709551615
** MIN: 0
** Will print a minimum of precision chars.
** If numlen < precision: print leading zeros.
** Return: bytes written to stdout, or -1 on error
*/

int	ft_putllu(unsigned long long nbr, int precision)
{
	int	numlen;

	numlen = ft_unumlen_base(nbr, 10);
	if (precision > numlen)
		if (ft_putnofc(precision - numlen, '0') == -1)
			return (-1);
	if (nbr == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
	}
	else if (output_llu(nbr) == -1)
		return (-1);
	if (precision > numlen)
		return (precision);
	return (numlen);
}
