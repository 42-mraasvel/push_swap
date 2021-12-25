/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dtoa_f.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 20:45:05 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 12:08:40 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_double.h"

static double	extract_fraction(double nbr,
				char *digits, int precision, int exp)
{
	int	c;

	if ((exp - 1023) > 51)
	{
		while (precision > 0)
		{
			*digits = '0';
			digits++;
			precision--;
		}
		return (0.0);
	}
	while (precision > 0)
	{
		nbr *= 10;
		c = (int)nbr;
		nbr -= c;
		if (c < 0)
			c = -c;
		*digits = c + '0';
		digits++;
		precision--;
	}
	return (nbr);
}

static double	extract_integers(double nbr, char *digits, int len)
{
	double	ten;
	int		c;

	ten = ft_pow(10, len - 1);
	while (ten >= 1.0)
	{
		c = (int)(nbr / ten);
		nbr -= ten * (double)c;
		ten /= 10;
		if (c < 0)
			c = -c;
		*digits = c + '0';
		digits++;
	}
	return (nbr);
}

char	*ft_dtoa_f(double nbr, int precision)
{
	t_double	d_union;
	char		*digits;
	char		rounding_digits[16];
	int			numlen;

	d_union.value = nbr;
	numlen = ft_numlen_dbl(nbr);
	digits = (char *)malloc((numlen + precision + 2) * sizeof(char));
	if (digits == NULL)
		return (NULL);
	digits[numlen + precision + 1] = '\0';
	nbr = extract_integers(nbr, digits, numlen);
	digits[numlen] = '.';
	if (precision > 0)
		nbr = extract_fraction(nbr, digits + numlen + 1,
				precision, d_union.bits.exponent);
	rounding_digits[15] = '\0';
	extract_fraction(nbr, rounding_digits, 15, d_union.bits.exponent);
	digits = ft_round_f(digits, rounding_digits);
	return (digits);
}
