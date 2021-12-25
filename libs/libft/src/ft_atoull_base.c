/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoull_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/14 23:21:10 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/14 23:46:17 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isbase(int base, char c)
{
	int	decision;

	c = ft_tolower(c);
	if (!ft_isalnum(c))
		return (0);
	if (ft_isdigit(c))
		decision = c - '0';
	else
		decision = c - 'a' + 10;
	if (decision >= base || decision < 0)
		return (0);
	return (1);
}

/*
** Return 0 for invalid base
*/

unsigned long long	ft_atoull_base(const char *str, int base)
{
	unsigned long long	num;
	char				digit;

	if (!ft_inrange(base, 2, 36))
		return (0);
	while (ft_isspace(*str))
		str++;
	num = 0;
	while (ft_isbase(base, *str))
	{
		digit = ft_tolower(*str);
		if (ft_isdigit(digit))
			num = (num * base) + digit - '0';
		else
			num = (num * base) + digit - 'a' + 10;
		str++;
	}
	return (num);
}
