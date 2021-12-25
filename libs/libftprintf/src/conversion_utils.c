/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conversion_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 19:43:46 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 12:07:53 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_conversion.h"
#include "libft.h"

int	put_n_chars_fast(int n, unsigned char c)
{
	size_t	remains;
	size_t	num;
	char	*large_buffer;

	remains = n % 10000;
	large_buffer = (char *)malloc(10000 * sizeof(char));
	if (large_buffer == 0)
		return (-1);
	ft_memset(large_buffer, c, 10000);
	num = n;
	while (num > 10000)
	{
		if (write(1, large_buffer, 10000) == -1)
		{
			free(large_buffer);
			return (-1);
		}
		num -= 10000;
	}
	if (write(1, large_buffer, remains) == -1)
		n = -1;
	free(large_buffer);
	return (n);
}

int	put_fw(int field_width, int zero)
{
	if (zero == 1)
	{
		if (ft_putnofc(field_width, '0') == -1)
			return (-1);
	}
	else if (ft_putnofc(field_width, ' ') == -1)
		return (-1);
	return (field_width);
}

unsigned long long	get_unsigned_nbr(va_list start, t_flags flags)
{
	unsigned long long	nbr;

	if (flags.l == 1)
		nbr = (unsigned long)va_arg(start, unsigned long);
	else if (flags.ll == 1)
		nbr = va_arg(start, unsigned long long);
	else if (flags.h == 1)
		nbr = (unsigned short)va_arg(start, unsigned int);
	else if (flags.hh == 1)
		nbr = (unsigned char)va_arg(start, unsigned int);
	else
		nbr = (unsigned int)va_arg(start, unsigned int);
	return (nbr);
}
