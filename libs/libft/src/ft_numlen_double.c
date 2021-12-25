/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numlen_double.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 10:16:11 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/28 22:57:42 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_numlen_dbl(double num)
{
	int	len;

	len = 0;
	while (num >= 10 || num <= -10)
	{
		len++;
		num = num / 10;
	}
	return (len + 1);
}
