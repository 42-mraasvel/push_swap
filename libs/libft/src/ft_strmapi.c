/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 10:38:05 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 11:49:39 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dest;
	unsigned int	i;

	if (s == 0 || f == 0)
		return (0);
	i = ft_strlen(s);
	dest = (char *)malloc((i + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	dest[i] = '\0';
	i = 0;
	while (s[i] != 0)
	{
		dest[i] = (*f)(i, s[i]);
		i++;
	}
	return (dest);
}
