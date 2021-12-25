/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 20:14:16 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 12:11:00 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_conversion.h"

/*
** Prints normal characters from the string.
** If it encounters a '%' sign, it will call the
** conversion function to read it.
** Bytes written are stored in the 'n' variable.
*/

static int	parse_string(const char *format, va_list start)
{
	size_t	i;
	int		n;
	int		return_value;

	i = 0;
	n = 0;
	while (format[i] != 0)
	{
		if (format[i] == '%')
		{
			i++;
			return_value = conversion(format, &i, start, n);
			if (return_value == -1)
				return (-1);
			n += return_value;
			continue ;
		}
		if (write(1, format + i, 1) == -1)
			return (-1);
		n++;
		i++;
	}
	return (n);
}

/*
** 1. Open the argument list
** 2. Call the main functions
** 3. Return values: bytes written or
** -1 on error.
*/

int	ft_printf(const char *format, ...)
{
	va_list	start;
	int		bytes_written;

	va_start(start, format);
	bytes_written = parse_string(format, start);
	va_end(start);
	return (bytes_written);
}
