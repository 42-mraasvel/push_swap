/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split_set.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 17:05:37 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 11:50:26 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** return 1 if c appears in set.
*/

static int	ft_isset(char c, const char *set)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

/*
** 1. Skip all delimiters
** 2. Either we are at the end, or at a new string.
** 3. Increment string count.
** 4. Skip all non-delimiters.
** 5. Repeat until end of string.
*/

static int	count_strings(const char *src, const char *set)
{
	int	i;
	int	string_count;

	i = 0;
	string_count = 0;
	while (src[i] != '\0')
	{
		while (ft_isset(src[i], set) == 1)
			i++;
		if (src[i] == '\0')
			break ;
		string_count++;
		while (src[i] != '\0' && ft_isset(src[i], set) == 0)
			i++;
	}
	return (string_count);
}

/*
** Free all previously successfully allocated strings.
*/

static void	*free_strings(char **strings, int string_count)
{
	while (string_count > 0)
	{
		string_count--;
		free(strings[string_count]);
	}
	free(strings);
	return (NULL);
}

/*
** 1. Find start of substring.
** 2. Find length of substring.
** 3. Call substr.
** 4. Repeat until end of string.
*/

static char	**fill_strings(char **strings, const char *src, const char *set)
{
	int	i;
	int	start;
	int	cnt;

	i = 0;
	cnt = 0;
	while (src[i] != '\0')
	{
		while (ft_isset(src[i], set) == 1)
			i++;
		if (src[i] == '\0')
			break ;
		start = i;
		while (src[i] != '\0' && ft_isset(src[i], set) == 0)
			i++;
		strings[cnt] = ft_substr(src, start, i - start);
		if (strings[cnt] == NULL)
			return (free_strings(strings, cnt));
		cnt++;
	}
	return (strings);
}

/*
** Will split string based on seperators in set.
*/

char	**ft_split_set(const char *src, const char *set)
{
	char	**strings;
	int		string_count;

	string_count = count_strings(src, set);
	strings = (char **)malloc((string_count + 1) * sizeof(char *));
	if (strings == NULL)
		return (NULL);
	strings[string_count] = NULL;
	strings = fill_strings(strings, src, set);
	return (strings);
}
