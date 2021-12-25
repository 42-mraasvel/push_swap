/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 10:33:54 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/11/03 12:53:06 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;

	d_len = 0;
	while (d_len < size && dst[d_len] != 0)
		d_len++;
	if (d_len == size)
		return (size + ft_strlen(src));
	s_len = ft_strlcpy(dst + d_len, src, size - d_len);
	return (d_len + s_len);
}
