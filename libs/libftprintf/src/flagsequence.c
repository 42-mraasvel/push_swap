/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flagsequence.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 09:11:51 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 12:11:38 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_conversion.h"

/*
** Sequence one flags:
** '#' '0' '-' ' ' '+'
** Creates the t_flags type struct, sets all values to 0,
** except for precision, for which 0 is a valid value.
** If a flag is encountered, it's value will be switched to 1.
** If no flags are encountered, all values will be equal to 0.
*/

t_flags	flags_sequence_one(const char *format, size_t *i)
{
	t_flags	flags;

	ft_bzero(&flags, sizeof(flags));
	flags.precision = -1;
	while (ft_is_printf_flag(format[*i]) == 1)
	{
		if (format[*i] == '#')
			flags.hash = 1;
		else if (format[*i] == '0')
			flags.zero = 1;
		else if (format[*i] == '-')
			flags.minus = 1;
		else if (format[*i] == ' ')
			flags.space = 1;
		else if (format[*i] == '+')
			flags.plus = 1;
		(*i)++;
	}
	return (flags);
}

static t_flags	check_field_width(const char *format, size_t *i,
		t_flags flags, va_list start)
{
	if (format[*i] == '*')
	{
		flags.field_width = va_arg(start, int);
		if (flags.field_width < 0)
		{
			flags.minus = 1;
			flags.field_width = -flags.field_width;
		}
		if (flags.field_width > 2147483614)
			flags.field_width = -2;
		(*i)++;
	}
	else if (format[*i] >= '1' && format[*i] <= '9')
	{
		flags.field_width = check_max_accepted_value(format + *i);
		if (flags.field_width == -2)
			return (flags);
		flags.field_width = ft_atoi(format + *i);
		while (ft_isdigit(format[*i]) != 0)
			(*i)++;
	}
	return (flags);
}

static t_flags	check_precision(const char *format, size_t *i,
		t_flags flags, va_list start)
{
	if (format[*i] == '.')
	{
		(*i)++;
		flags.precision = 0;
		if (format[*i] == '*')
		{
			flags.precision = va_arg(start, int);
			if (flags.precision < 0)
				flags.precision = -1;
			if (flags.precision > 2147483614)
				flags.precision = -2;
			(*i)++;
		}
		else if (ft_isdigit(format[*i]) != 0)
		{
			flags.precision = check_max_accepted_value(format + *i);
			if (flags.precision == -2)
				return (flags);
			flags.precision = ft_atoi(format + *i);
			while (ft_isdigit(format[*i]) != 0)
				(*i)++;
		}
	}
	return (flags);
}

/*
** check field width and precision flags.
** FW and Precision can be taken as '*' (argument) or as string value.
** In case of string, ft_atoi is used to convert it (if there is no overflow).
** In case of '*' it is taken as an int data type.
**
** warning: precision can be equal to zero.
** 2147483614 was the maximum digit printf would still take
** This function returns -2 on either field width or precision
** in case of that error (integer overflow).
*/

t_flags	flags_sequence_two(const char *format, size_t *i,
		t_flags flags, va_list start)
{
	flags = check_field_width(format, i, flags, start);
	if (flags.field_width == -2)
		return (flags);
	flags = check_precision(format, i, flags, start);
	return (flags);
}

/*
** Sequence 3 checks for 'l' 'll' 'h' and 'hh' flags.
*/

t_flags	flags_sequence_three(const char *format,
				size_t *i, t_flags flags)
{
	if (format[*i] == 'l')
	{
		if (format[*i + 1] == 'l')
			flags.ll = 1;
		else
			flags.l = 1;
	}
	else if (format[*i] == 'h')
	{
		if (format[*i + 1] == 'h')
			flags.hh = 1;
		else
			flags.h = 1;
	}
	if (flags.hh == 1 || flags.ll == 1)
		(*i) += 2;
	else if (flags.h == 1 || flags.l == 1)
		(*i) += 1;
	return (flags);
}
