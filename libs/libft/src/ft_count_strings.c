/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_count_strings.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 22:18:52 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/02 22:19:14 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_count_strings(char **strings)
{
	size_t	i;

	i = 0;
	while (strings[i] != NULL)
		i++;
	return (i);
}
