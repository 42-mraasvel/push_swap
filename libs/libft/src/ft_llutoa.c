/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_llutoa.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 16:46:29 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 11:50:06 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	utoa_fill_string(unsigned long long nbr, char *result)
{
	if (nbr < 10)
	{
		*result = nbr % 10 + '0';
	}
	else
	{
		utoa_fill_string(nbr / 10, result - 1);
		*result = nbr % 10 + '0';
	}
}

char	*ft_llutoa(unsigned long long nbr, int min_len)
{
	char	*result;
	int		len;

	len = ft_numlen_base(nbr, 10);
	if (len < min_len)
		len = min_len;
	result = (char *)ft_calloc((len + 1), sizeof(char));
	if (result == NULL)
		return (NULL);
	utoa_fill_string(nbr, result + (len - 1));
	len = 0;
	while (result[len] == '\0')
	{
		result[len] = '0';
		len++;
	}
	return (result);
}
