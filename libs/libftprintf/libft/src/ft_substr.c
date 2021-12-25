/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 19:54:14 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 11:50:33 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*substr;

	if (s == 0)
		return (0);
	slen = ft_strlen(s);
	if (slen <= start)
		return ((char *)ft_calloc(1, sizeof(char)));
	slen = slen - start;
	if (slen < len)
		len = slen;
	substr = malloc((len + 1) * sizeof(char));
	if (substr == 0)
		return (0);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
