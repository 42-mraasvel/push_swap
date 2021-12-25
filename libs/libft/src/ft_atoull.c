/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoull.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 09:46:10 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/14 09:48:35 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_atoull(char *str)
{
	unsigned long long	nbr;
	int					i;

	i = 0;
	while (ft_isspace(str[i]) != 0)
		i++;
	if (str[i] == '+')
		i++;
	nbr = 0;
	while (ft_isdigit(str[i]) != 0)
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (nbr);
}
