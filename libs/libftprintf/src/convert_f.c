/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_f.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 11:58:19 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 12:09:22 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_double.h"
#include "libft.h"

static int	get_fchars_count(t_double nbr, t_flags flags, char *digits)
{
	int	len;

	len = ft_strlen(digits);
	if (digits[len - 1] == '.' && flags.hash == 0)
	{
		digits[len - 1] = '\0';
		len--;
	}
	if (nbr.bits.sign == 1 || flags.plus == 1 || flags.space == 1)
		len++;
	return (len);
}

static int	output_f(t_double nbr, t_flags flags, char *digits)
{
	int	chars;

	chars = get_fchars_count(nbr, flags, digits);
	if (flags.minus == 0 && flags.zero == 0 && flags.field_width > chars)
		if (put_fw(flags.field_width - chars, 0) == -1)
			return (-1);
	if (nbr.bits.sign == 1)
		if (write(1, "-", 1) == -1)
			return (-1);
	if (nbr.bits.sign == 0 && flags.plus == 1)
		if (write(1, "+", 1) == -1)
			return (-1);
	if (nbr.bits.sign == 0 && flags.space == 1)
		if (write(1, " ", 1) == -1)
			return (-1);
	if (flags.zero == 1 && flags.field_width > chars)
		if (put_fw(flags.field_width - chars, flags.zero) == -1)
			return (-1);
	if (ft_putstr(digits) == -1)
		return (-1);
	if (flags.minus == 1 && flags.field_width > chars)
		if (put_fw(flags.field_width - chars, 0) == -1)
			return (-1);
	return (ft_max(chars, flags.field_width));
}

static int	put_inf_or_nan(t_double nbr, t_flags flags)
{
	if (nbr.bits.mantissa != 0)
	{
		if (write(1, "nan", 3) == -1)
			return (-1);
		return (3);
	}
	if (nbr.bits.sign == 1)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
	}
	else if (flags.plus == 1)
	{
		if (write(1, "+", 1) == -1)
			return (-1);
	}
	else if (flags.space == 1)
		if (write(1, " ", 1) == -1)
			return (-1);
	return (write(1, "inf", 3));
}

int	inf_nan(t_double nbr, t_flags flags)
{
	int	chars;

	chars = 3;
	if (nbr.bits.mantissa == 0
		&& (nbr.bits.sign == 1 || flags.plus == 1 || flags.space == 1))
		chars++;
	if (flags.minus == 0 && flags.field_width > chars)
		if (put_fw(flags.field_width - chars, 0) == -1)
			return (-1);
	if (put_inf_or_nan(nbr, flags) == -1)
		return (-1);
	if (flags.minus == 1 && flags.field_width > chars)
		if (put_fw(flags.field_width - chars, 0) == -1)
			return (-1);
	return (ft_max(chars, flags.field_width));
}

/*
** For floats, we first put all the digits into a string,
** this makes rounding and counting output easier.
** Edge cases are: '+inf' '-inf' 'nan'.
** Rounding is done by looking at the next 15-16 digits.
*/

int	convert_f(va_list start, t_flags flags)
{
	t_double	nbr;
	char		*digits;
	int			chars;

	nbr.value = va_arg(start, double);
	if (flags.minus == 1 || nbr.bits.exponent == 2047)
		flags.zero = 0;
	if (flags.plus == 1)
		flags.space = 0;
	if (flags.precision < 0)
		flags.precision = 6;
	if (nbr.bits.exponent == 2047)
		return (inf_nan(nbr, flags));
	digits = ft_dtoa_f(nbr.value, flags.precision);
	if (digits == NULL)
		return (-1);
	chars = output_f(nbr, flags, digits);
	free(digits);
	return (chars);
}
