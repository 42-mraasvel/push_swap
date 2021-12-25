/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 13:37:56 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 11:48:41 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_substr_len(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s1[i] != 0)
	{
		if (ft_strchr(set, s1[i]) == 0)
			len = i;
		i++;
	}
	return (len + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	size_t			len;

	if (set == 0 && s1 != 0)
		return (ft_strdup(s1));
	else if (s1 == 0)
		return (0);
	start = 0;
	while (s1[start] != 0 && ft_strchr(set, s1[start]) != 0)
		start++;
	if (s1[start] == 0)
		return ((char *)ft_calloc(1, sizeof(char)));
	len = find_substr_len(s1 + start, set);
	return (ft_substr(s1, start, len));
}
