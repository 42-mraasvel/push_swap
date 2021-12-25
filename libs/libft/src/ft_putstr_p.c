/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_p.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 20:43:10 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/16 23:28:30 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/*
** Will put at most precision chars.
** Returns bytes written.
** Return -1 on write error, or NULL pointer.
*/

ssize_t	ft_putstr_p(char *str, ssize_t precision)
{
	ssize_t	len;

	if (str == 0)
		return (-1);
	if (precision == 0)
		return (0);
	len = ft_strlen(str);
	if (precision < len)
		len = precision;
	return (write(1, str, len));
}
