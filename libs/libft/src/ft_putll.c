/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putll.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 10:11:31 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/16 23:21:06 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/*
** MAX:  9223372036854775807
** MIN: -9223372036854775808
** Will print a minimum of precision chars.
** If numlen < precision: print leading zeros.
** Return: bytes written to stdout, or -1 on error
*/

int	ft_putll(long long nbr, int precision)
{
	int	numlen;

	numlen = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		numlen = ft_unumlen_base(-nbr, 10);
		nbr = -nbr;
	}
	else
		numlen = ft_unumlen_base(nbr, 10);
	if (precision > numlen)
		if (ft_putnofc(precision - numlen, '0') == -1)
			return (-1);
	if (ft_putllu(nbr, 0) == -1)
		return (-1);
	if (precision > numlen)
		return (precision);
	return (numlen);
}
