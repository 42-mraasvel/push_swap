/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 11:35:02 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 11:51:40 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*ptc;

	if ((char)c == '\0')
		return (ft_strchr(s, '\0'));
	i = 0;
	ptc = (char *)s;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			ptc = ((char *)s + i);
		i++;
	}
	if (*ptc == (char)c)
		return (ptc);
	return (NULL);
}
