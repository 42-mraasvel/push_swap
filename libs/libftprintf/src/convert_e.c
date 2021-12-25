/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_e.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 13:17:37 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 12:10:30 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_double.h"
#include "libft.h"

static int	get_echars_count(t_double nbr, t_flags flags, char *digits)
{
	int	len;

	len = ft_strlen(digits);
	if (flags.precision == 0 && flags.hash == 0)
		len--;
	if (nbr.bits.sign == 1 || flags.plus == 1 || flags.space == 1)
		len++;
	return (len);
}

static int	put_double_sn(t_double nbr, t_flags flags, char *digits, int chars)
{
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
	if (flags.hash == 0 && flags.precision == 0)
	{
		if (write(1, digits, 1) == -1)
			return (-1);
		if (ft_putstr(digits + 2) == -1)
			return (-1);
	}
	else if (ft_putstr(digits) == -1)
		return (-1);
	return (chars);
}

static int	output_e(t_double nbr, t_flags flags, char *digits)
{
	int	chars;

	chars = get_echars_count(nbr, flags, digits);
	if (flags.minus == 0 && flags.zero == 0 && flags.field_width > chars)
		if (put_fw(flags.field_width - chars, 0) == -1)
			return (-1);
	if (put_double_sn(nbr, flags, digits, chars) == -1)
		return (-1);
	if (flags.minus == 1 && flags.field_width > chars)
		if (put_fw(flags.field_width - chars, 0) == -1)
			return (-1);
	return (ft_max(chars, flags.field_width));
}

int	convert_e(va_list start, t_flags flags)
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
	digits = ft_dtoa_e(nbr.value, flags.precision);
	if (digits == NULL)
		return (-1);
	chars = output_e(nbr, flags, digits);
	free(digits);
	return (chars);
}
