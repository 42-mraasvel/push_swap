/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_hex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 15:10:50 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 12:07:37 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_conversion.h"

static int	get_xchars_count(unsigned long long nbr, t_flags flags)
{
	int	len;

	len = 0;
	if (flags.precision == 0 && nbr == 0)
		return (0);
	len = ft_unumlen_base(nbr, 16);
	len = ft_max(len, flags.precision);
	if (flags.hash == 1 && nbr != 0)
		len += 2;
	return (len);
}

static int	print_hex(unsigned long long nbr, t_flags flags, int upcase)
{
	int	hash;

	hash = 0;
	if (flags.hash == 1 && nbr != 0)
	{
		if (upcase != 0)
		{
			if (write(1, "0X", 2) == -1)
				return (-1);
		}
		else if (write(1, "0x", 2) == -1)
			return (-1);
		hash = 2;
	}
	if (flags.zero == 1)
	{
		if (ft_putllu_base(nbr, 16, flags.field_width - hash, upcase) == -1)
			return (-1);
	}
	else if (ft_putllu_base(nbr, 16, flags.precision, upcase) == -1)
		return (-1);
	return (0);
}

/*
** FLAGS: '#' '0' '-' MFW OP
** 'l' = unsigned long 'll' = unsigned long long
** 'h' = unsigned short 'hh' unsigned char
** Prints alphabetical chars in uppercase if upcase != 0.
*/

int	convert_hex(va_list start, t_flags flags, int upcase)
{
	unsigned long long	nbr;
	int					chars;

	if (flags.precision >= 0 || flags.minus == 1)
		flags.zero = 0;
	nbr = get_unsigned_nbr(start, flags);
	chars = get_xchars_count(nbr, flags);
	if (flags.zero == 0 && flags.minus == 0 && flags.field_width > chars)
		if (put_fw(flags.field_width - chars, 0) == -1)
			return (-1);
	if (!(nbr == 0 && flags.precision == 0))
		print_hex(nbr, flags, upcase);
	if (flags.minus == 1 && flags.field_width > chars)
		if (put_fw(flags.field_width - chars, 0) == -1)
			return (-1);
	return (ft_max(chars, flags.field_width));
}
