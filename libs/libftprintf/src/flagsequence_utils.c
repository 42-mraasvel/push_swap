/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flagsequence_utils.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 09:30:05 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 12:06:21 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Simply returns 1 if the char
** is any of the sequence 1 flags.
*/

int	ft_is_printf_flag(char c)
{
	if (c == '#' || c == '0' || c == '-')
		return (1);
	if (c == ' ' || c == '+')
		return (1);
	return (0);
}

/*
** Checks field_width and precision string values.
** Returns (-2) if value exceeds 2147483614.
** This is the maximum value printf would accept (for me).
*/

int	check_max_accepted_value(const char *number)
{
	size_t	i;
	size_t	leading_zeros;
	int		smaller;
	char	max_value[11];

	i = 0;
	smaller = 0;
	leading_zeros = 0;
	while (number[leading_zeros] == '0')
		leading_zeros++;
	ft_strlcpy(max_value, "2147483645", 11);
	while (ft_isdigit(number[i + leading_zeros]) != 0)
	{
		if (smaller == 0 && number[i + leading_zeros] < max_value[i])
			smaller = 1;
		if (smaller == 0 && number[i + leading_zeros] > max_value[i])
			smaller = -1;
		if (max_value[i] == '\0')
			return (-2);
		i++;
	}
	if (smaller == -1 && max_value[i] == '\0')
		return (-2);
	return (0);
}
