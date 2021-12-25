/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_join_n_strings.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 13:59:43 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 11:51:25 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

static int	get_total_len(int cnt, va_list start)
{
	int	i;
	int	total_len;

	i = 0;
	total_len = 0;
	while (i < cnt)
	{
		total_len += ft_strlen(va_arg(start, const char *));
		i++;
	}
	return (total_len);
}

char	*ft_join_n_strings(int cnt, ...)
{
	va_list	start;
	char	*big_string;
	int		len;

	va_start(start, cnt);
	len = get_total_len(cnt, start);
	va_end(start);
	big_string = (char *)ft_calloc((len + 1), sizeof(char));
	if (big_string == NULL)
		return (NULL);
	va_start(start, cnt);
	while (cnt > 0)
	{
		ft_strlcat(big_string, va_arg(start, const char *), len + 1);
		cnt--;
	}
	return (big_string);
}
