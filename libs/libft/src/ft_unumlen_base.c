/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_unumlen_base.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 10:14:00 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/16 23:22:00 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** Takes non-negative decimal integer as input.
** Divides by base to get digit count.
** Returns digit count for nbr in base-version.
*/

int	ft_unumlen_base(unsigned long long nbr, int base)
{
	int	len;

	if (nbr == 0)
		return (1);
	len = 0;
	while (nbr != 0)
	{
		nbr = nbr / base;
		len++;
	}
	return (len);
}
