/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 11:48:46 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 11:49:06 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	if (*little == 0)
		return ((char *)big);
	if (len == 0)
		return (0);
	i = 0;
	little_len = ft_strlen(little);
	while (i < len && big[i] != 0)
	{
		if (i + little_len > len)
			return (0);
		if (big[i] == little[0])
		{
			if (ft_strncmp(big + i, little, little_len) == 0)
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
