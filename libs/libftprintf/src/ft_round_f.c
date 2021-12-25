/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_round_f.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 10:55:14 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 12:12:37 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*put_one(char *nbr)
{
	char	*result;

	result = ft_strjoin("1", nbr);
	free(nbr);
	return (result);
}

static char	*round_num(char *nbr, char rounder)
{
	int		end;

	end = ft_strlen(nbr) - 1;
	while (nbr[end] == '9' && end >= 0)
	{
		nbr[end] = '0';
		end--;
		if (nbr[end] == '.')
			end--;
	}
	if (end == -1)
		return (put_one(nbr));
	if (rounder == '5' && nbr[end] == '.' && nbr[end - 1] % 2 == 0)
		return (nbr);
	if (nbr[end] == '.')
		end--;
	if (nbr[end] == '9')
	{
		nbr[end] = '0';
		return (put_one(nbr));
	}
	nbr[end]++;
	return (nbr);
}

char	*ft_round_f(char *nbr, char *rounder)
{
	char	rounding_digit;
	int		i;

	rounding_digit = rounder[0];
	i = 1;
	if (rounder[0] == '4')
	{
		while (rounder[i] >= '9')
			i++;
		if (rounder[i] == '\0')
			rounding_digit = '5';
	}
	else if (rounder[0] == '5')
	{
		while (rounder[i] == '0')
			i++;
		if (rounder[i] != '\0')
			rounding_digit = '6';
	}
	if (rounding_digit < '5')
		return (nbr);
	nbr = round_num(nbr, rounding_digit);
	return (nbr);
}
