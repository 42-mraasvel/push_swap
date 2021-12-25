/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_digit.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 09:34:01 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 12:10:15 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_conversion.h"

static long long	get_signed_nbr(va_list start, t_flags flags)
{
	long long	nbr;

	if (flags.l == 1)
		nbr = (long)va_arg(start, long);
	else if (flags.ll == 1)
		nbr = va_arg(start, long long);
	else if (flags.h == 1)
		nbr = (short)va_arg(start, int);
	else if (flags.hh == 1)
		nbr = (signed char)va_arg(start, int);
	else
		nbr = (int)va_arg(start, int);
	return (nbr);
}

/*
** Returns amount of chars that will be printed.
*/

static int	get_dchars_count(long long nbr, t_flags flags)
{
	int	len;

	len = 0;
	if (nbr < 0 || flags.plus == 1 || flags.space == 1)
		len++;
	if (nbr == 0 && flags.precision == 0)
		return (len);
	len += ft_numlen_base(nbr, 10);
	if (flags.precision >= len
		&& (flags.plus == 1 || flags.space == 1 || nbr < 0))
		return (flags.precision + 1);
	return (ft_max(len, flags.precision));
}

/*
** If zero flag is active and no precision:
** print leading zero's from field width.
*/

static int	print_digit(long long nbr, t_flags flags, int chars)
{
	if (flags.plus == 1 && nbr >= 0)
	{
		if (write(1, "+", 1) == -1)
			return (-1);
	}
	else if (flags.space == 1 && nbr >= 0)
		if (write(1, " ", 1) == -1)
			return (-1);
	if (nbr == 0 && flags.precision == 0)
		return (chars);
	if (flags.zero == 1)
	{
		if (flags.plus == 1 || flags.space == 1 || nbr < 0)
		{
			if (ft_putll(nbr, flags.field_width - 1) == -1)
				return (-1);
		}
		else if (ft_putll(nbr, flags.field_width) == -1)
			return (-1);
	}
	else if (ft_putll(nbr, flags.precision) == -1)
		return (-1);
	return (chars);
}

/*
** Flags: '0' '-' ' ' '+'
** Field Width, Precision
** 'l' 'll' 'h' 'hh'
*/

int	convert_digit(va_list start, t_flags flags)
{
	long long	nbr;
	int			chars;

	nbr = get_signed_nbr(start, flags);
	chars = get_dchars_count(nbr, flags);
	if (flags.precision >= 0 || flags.minus == 1)
		flags.zero = 0;
	if (flags.minus == 0 && flags.zero == 0 && flags.field_width > chars)
		if (put_fw(flags.field_width - chars, 0) == -1)
			return (-1);
	print_digit(nbr, flags, chars);
	if (flags.minus == 1 && flags.field_width > chars)
		if (put_fw(flags.field_width - chars, 0) == -1)
			return (-1);
	return (ft_max(chars, flags.field_width));
}
