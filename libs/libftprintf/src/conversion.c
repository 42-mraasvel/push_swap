/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conversion.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 09:01:17 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 12:13:38 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_conversion.h"

static int	invalid_conversion(char conversion_type, t_flags flags)
{
	if (flags.minus == 0 && flags.field_width > 1)
		if (put_fw(flags.field_width - 1, flags.zero) == -1)
			return (-1);
	if (write(1, &conversion_type, 1) == -1)
		return (-1);
	if (flags.minus == 1 && flags.field_width > 1)
		if (put_fw(flags.field_width - 1, 0) == -1)
			return (-1);
	return (ft_max(1, flags.field_width));
}

/*
** Reads conversion char and calls it's function.
** Returns bytes written if conversion char is valid.
** Returns -1 if conversion char is invalid.
*/

static int	conversion_caller(char conversion_type,
			va_list start, t_flags flags, int n)
{
	if (conversion_type == 'c')
		return (convert_character(start, flags));
	if (conversion_type == 's')
		return (convert_string(start, flags));
	if (conversion_type == 'p')
		return (convert_pointer(start, flags));
	if (conversion_type == 'd')
		return (convert_digit(start, flags));
	if (conversion_type == 'i')
		return (convert_digit(start, flags));
	if (conversion_type == 'u')
		return (convert_udigit(start, flags));
	if (conversion_type == 'x')
		return (convert_hex(start, flags, 0));
	if (conversion_type == 'X')
		return (convert_hex(start, flags, 1));
	if (conversion_type == 'n')
		return (convert_n(start, flags, n));
	if (conversion_type == 'f')
		return (convert_f(start, flags));
	if (conversion_type == 'g')
		return (0);
	if (conversion_type == 'e')
		return (convert_e(start, flags));
	return (-2);
}

/*
** t_flags contains boolean values for each flag.
** Reads in flags in sequence like real printf:
** 1. Sequence one: '#0- +'.
** 2. Sequence two: Minimum Field Width and Precision.
** if the values are too large, it will return an error.
** 3. Sequence three: Length Modifiers ('l', 'll', 'h' and 'hh').
** In the sequence functions:
** index i is incremented to point to the conversion char.
** Definitions of these functions are in flagsequence.c
**
** If the conversion character is invalid, it will print the S1 and S2 flags,
** only one copy of each flag, in the expected order.
**
** If the flags and conversion character are correct,
** the appropriate conversion function is called.
** Return value is equal to the bytes written, or -1 on error.
** Index i will be incremented to point to the next char.
*/

int	conversion(const char *format, size_t *i, va_list start, int n)
{
	t_flags	flags;
	int		return_value;

	flags = flags_sequence_one(format, i);
	flags = flags_sequence_two(format, i, flags, start);
	if (flags.field_width == -2 || flags.precision == -2)
		return (-1);
	flags = flags_sequence_three(format, i, flags);
	return_value = conversion_caller(format[*i], start, flags, n);
	if (return_value == -2)
		return_value = invalid_conversion(format[*i], flags);
	else if (return_value == -1)
		return (-1);
	(*i)++;
	return (return_value);
}
