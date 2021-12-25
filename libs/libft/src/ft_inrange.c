/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_inrange.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/28 20:25:00 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/01/28 20:35:52 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** Checks if number is in particular range
*/

int	ft_inrange(int num, int min, int max)
{
	if (num < min || num > max)
		return (0);
	return (1);
}

int	ft_inrangef(float num, float min, float max)
{
	if (num < min || num > max)
		return (0);
	return (1);
}

int	ft_inrangell(long long num, long long min, long long max)
{
	if (num < min || num > max)
		return (0);
	return (1);
}
