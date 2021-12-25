/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_bonus2.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/11 09:31:22 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/11 09:38:09 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker_bonus.h"

char	*getcolor(t_dlist *p, t_printing *info)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (p == info->last[i])
			return (info->colors[0]);
		i++;
	}
	return (info->colors[1]);
}

void	color_init(t_printing *info)
{
	ft_strcpy(info->colors[0], REDCLR);
	ft_strcpy(info->colors[1], EMPTYSTR);
}
