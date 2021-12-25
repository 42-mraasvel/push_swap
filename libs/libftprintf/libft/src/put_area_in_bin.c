/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_area_in_bin.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/18 11:55:39 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 11:51:47 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	put_binary_representation_of_area(void *area, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)area;
	while (n > 0)
	{
		n--;
		if (ft_putllu_base(ptr[n], 2, 8, 0) == -1)
			return (-1);
		if (n != 0)
			if (write(1, " ", 1) == -1)
				return (-1);
	}
	return (71);
}

int	put_hex_representation_of_area(void *area, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)area;
	while (n > 0)
	{
		n--;
		if (write(1, "x", 1) == -1)
			return (-1);
		if (ft_putllu_base(ptr[n], 16, 2, 0) == -1)
			return (-1);
		if (n != 0)
			if (write(1, " ", 1) == -1)
				return (-1);
	}
	return (31);
}
