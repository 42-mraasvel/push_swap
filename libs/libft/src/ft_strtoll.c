/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtoll.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/18 13:43:35 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/03/18 14:56:50 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <errno.h>
#include "libft.h"

/*
** Sets errno to ERANGE if overflow occurs
*/

static long long int	check_overflow(long long int result, char digit)
{
	long long	tmp;

	tmp = result * 10;
	if (tmp / 10 != result)
		errno = ERANGE;
	tmp = (result * 10) + (long long)digit - '0';
	if (tmp < 0)
		errno = ERANGE;
	return (tmp);
}

static int	isminlong(const char *nptr)
{
	if (ft_strncmp(nptr, "-9223372036854775808", 20) != 0)
		return (0);
	if (ft_isdigit(nptr[20]))
		return (0);
	return (1);
}

long long int	ft_strtoll(const char *nptr)
{
	long long int	result;
	int				negative;

	while (ft_isspace(*nptr))
		nptr++;
	negative = 1;
	if (*nptr == '-')
		negative = -1;
	if (negative == -1 && isminlong(nptr))
		return (LLONG_MIN);
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	result = 0;
	while (ft_isdigit(*nptr))
	{
		result = check_overflow(result, *nptr);
		nptr++;
	}
	if (negative == -1)
		return (-result);
	return (result);
}
