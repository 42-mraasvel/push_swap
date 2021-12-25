/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchri.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/14 22:46:02 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/03/14 22:47:15 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_strchri(const char *s, int c)
{
	char	*r;

	r = (char *)s;
	while (*r != 0 && *r != (char)c)
		r++;
	if (*r != (char)c)
		return (-1);
	return (r - s);
}
