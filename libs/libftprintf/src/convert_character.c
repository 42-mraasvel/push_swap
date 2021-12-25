/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_character.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 18:27:59 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 12:13:26 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_conversion.h"

/*
** Flags: '-' Field Width.
** va_arg automatically "upcasts" the char to int.
** Potential '%lc' option for wint_t (wide char) with bonus(?)
*/

int	convert_character(va_list start, t_flags flags)
{
	unsigned char	c;
	int				chars;

	chars = ft_max(flags.field_width, 1);
	if (flags.minus == 0 && chars > 1)
		if (put_fw(chars - 1, 0) == -1)
			return (-1);
	c = (unsigned char)va_arg(start, int);
	if (write(1, &c, 1) == -1)
		return (-1);
	if (flags.minus == 1 && chars > 1)
		if (put_fw(chars - 1, 0) == -1)
			return (-1);
	return (chars);
}
