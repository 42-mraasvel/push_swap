/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split_token.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/05 16:47:16 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 11:49:51 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*find_non_token(const char *src, const char *token, int token_len)
{
	while (*src != '\0')
	{
		if (*src != *token)
			return ((char *)src);
		if (ft_strncmp(src, token, token_len) != 0)
			return ((char *)src);
		src += token_len;
	}
	return (NULL);
}

static int	count_strings_token(const char *src, const char *token)
{
	int	count;
	int	token_len;

	count = 0;
	token_len = ft_strlen(token);
	while (*src != '\0')
	{
		src = find_non_token(src, token, token_len);
		if (src == NULL)
			break ;
		count++;
		src = ft_strstr(src, token);
		if (src == NULL)
			break ;
	}
	return (count);
}

static void	*ft_free_split_on_error(char **strings, int index)
{
	while (index > 0)
	{
		index--;
		free(strings[index]);
	}
	free(strings);
	return (NULL);
}

static char	**fill_strings(char **strings, const char *src, const char *token)
{
	char	*end;
	int		index;
	int		token_len;

	index = 0;
	token_len = ft_strlen(token);
	while (*src != '\0')
	{
		src = find_non_token(src, token, token_len);
		if (src == NULL)
			break ;
		end = ft_strstr(src, token);
		if (end == NULL)
			strings[index] = ft_strdup(src);
		else
			strings[index] = ft_substr(src, 0, end - src);
		if (strings[index] == NULL)
			return (ft_free_split_on_error(strings, index));
		if (end == NULL)
			break ;
		index++;
		src = end;
	}
	return (strings);
}

/*
** Split strings based on token.
** "aaabbaaab" with token "bb" will return "aaa" "aaab" "NULL"
*/

char	**ft_split_token(const char *src, const char *token)
{
	char	**strings;
	int		string_count;

	string_count = count_strings_token(src, token);
	strings = (char **)malloc((string_count + 1) * sizeof(char *));
	if (strings == NULL)
		return (NULL);
	strings[string_count] = NULL;
	strings = fill_strings(strings, src, token);
	return (strings);
}
