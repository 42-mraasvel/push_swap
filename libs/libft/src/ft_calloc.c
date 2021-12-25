/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 14:45:43 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 11:51:15 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*m;

	m = (void *)malloc(nmemb * size);
	if (m == 0 || nmemb * size == 0)
		return (m);
	ft_bzero(m, size * nmemb);
	return (m);
}
