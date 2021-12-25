/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atof.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/28 15:08:36 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/16 23:27:33 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_double.h"

static double	get_fraction(char *str)
{
	double	fraction;
	double	m;
	size_t	i;

	i = 0;
	fraction = 0;
	m = 10;
	while (ft_isdigit(str[i]) != 0)
	{
		fraction += (str[i] - '0') / m;
		m *= 10;
		i++;
	}
	return (fraction);
}

static double	get_value(char *str)
{
	size_t	i;
	double	num;

	i = 0;
	num = 0;
	while (ft_isdigit(str[i]) != 0)
	{
		num = (num * 10) + str[i] - '0';
		i++;
	}
	if (str[i] == '.')
		num += get_fraction(str + i + 1);
	return (num);
}

double	ft_atof(char *str)
{
	t_double	nbr;
	size_t		i;
	char		sign;

	i = 0;
	while (ft_isspace(str[i]) != 0)
		i++;
	sign = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = 1;
		i++;
	}
	if (ft_isdigit(str[i]) == 0)
		return (0);
	while (str[i] == '0')
		i++;
	nbr.value = get_value(str + i);
	nbr.bits.sign = sign;
	return (nbr.value);
}
