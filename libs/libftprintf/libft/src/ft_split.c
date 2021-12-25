/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 21:02:00 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 11:52:47 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_count_substrings(char const *s, char c)
{
	size_t		count;

	count = 0;
	while (*s != 0)
	{
		while (*s == c)
			s++;
		if (*s == 0)
			break ;
		count++;
		while (*s != c && *s != 0)
			s++;
	}
	return (count);
}

static void	ft_free_strings(char **strings, unsigned int index)
{
	while (index > 0)
	{
		index--;
		free(strings[index]);
	}
	free(strings);
}

static char	**find_substrings(char **strings, char const *s, char c)
{
	unsigned int	i;
	char const		*end;

	i = 0;
	while (*s != 0)
	{
		while (*s == c)
			s++;
		if (*s == 0)
			break ;
		end = ft_strchr(s, c);
		if (end == 0)
			end = s + ft_strlen(s);
		strings[i] = ft_substr(s, 0, end - s);
		if (strings[i] == 0)
		{
			ft_free_strings(strings, i - 1);
			return (0);
		}
		i++;
		while (*s != c && *s != 0)
			s++;
	}
	return (strings);
}

char	**ft_split(char const *s, char c)
{
	char			**strings;
	size_t			string_count;

	if (s == 0)
		return (0);
	string_count = ft_count_substrings(s, c);
	strings = (char **)ft_calloc(string_count + 1, sizeof(char *));
	if (strings == 0)
		return (0);
	if (string_count != 0)
		strings = find_substrings(strings, s, c);
	return (strings);
}
