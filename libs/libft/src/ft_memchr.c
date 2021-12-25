/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/25 15:37:02 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 11:50:42 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*pts;

	pts = (const unsigned char *)s;
	while (n > 0)
	{
		if (*pts == (unsigned char)c)
			return ((void *)pts);
		pts++;
		n--;
	}
	return (0);
}
