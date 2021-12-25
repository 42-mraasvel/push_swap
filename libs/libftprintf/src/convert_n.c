/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_n.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 16:17:34 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 12:06:09 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_conversion.h"

/*
** FLAGS:
** 'l' = long* 'll' = long long*
** 'h' = short* 'hh' = signed char*
*/

int	convert_n(va_list start, t_flags flags, int n)
{
	void	*ptr;

	if (flags.l == 1)
		ptr = va_arg(start, long *);
	else if (flags.ll == 1)
		ptr = va_arg(start, long long *);
	else if (flags.h == 1)
		ptr = va_arg(start, short *);
	else if (flags.hh == 1)
		ptr = va_arg(start, signed char *);
	else
		ptr = va_arg(start, int *);
	*(int *)ptr = n;
	return (0);
}
