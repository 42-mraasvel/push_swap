/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putllu_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 22:03:47 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/16 23:26:44 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static char	*get_base(int base, int upcase)
{
	char	*base_chars;
	int		i;
	int		digit;

	base_chars = malloc(base * sizeof(char));
	if (base_chars == 0)
		return (0);
	i = 0;
	while (i < base)
	{
		digit = i + 'a' - 10;
		if (i < 10)
			digit = i + '0';
		else if (upcase == 1)
			digit = i + 'A' - 10;
		base_chars[i] = digit;
		i++;
	}
	return (base_chars);
}

static int	output_llu_base(unsigned long long nbr, int base, char *base_chars)
{
	if (nbr < (unsigned long long)base)
	{
		if (write(1, base_chars + nbr, 1) == -1)
			return (-1);
		return (0);
	}
	else
	{
		if (output_llu_base(nbr / base, base, base_chars) == -1)
			return (-1);
		if (write(1, base_chars + (nbr % base), 1) == -1)
			return (-1);
	}
	return (0);
}

/*
** Prints number in given base.
** Will use alphabet up to base 36.
** 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ
** Upcase = 0 means lowercase, otherwise print uppercase.
** Minimum of precision chars printed.
** If numlen < precision: print leading zero's.
** Uses malloc to get base.
** Returns total chars printed or -1 on error.
*/

int	ft_putllu_base(unsigned long long nbr,
		int base, int precision, int upcase)
{
	char	*base_chars;
	int		numlen;

	if (!(base >= 2 && base <= 36))
		return (-1);
	base_chars = get_base(base, upcase);
	if (base_chars == 0)
		return (-1);
	numlen = ft_unumlen_base(nbr, base);
	if (numlen < precision)
		if (ft_putnofc(precision - numlen, '0') == -1)
			return (-1);
	if (output_llu_base(nbr, base, base_chars) == -1)
		return (-1);
	free(base_chars);
	if (precision > numlen)
		return (precision);
	return (numlen);
}
