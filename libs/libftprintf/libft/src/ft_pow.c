/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pow.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 10:15:53 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/11/21 11:52:32 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

double	ft_pow(double x, double y)
{
	double	result;

	if (y == 0.0)
		return (1);
	result = 1;
	if (y < 0)
		return (result / ft_pow(x, -y));
	while (y > 0)
	{
		result *= x;
		y--;
	}
	return (result);
}
