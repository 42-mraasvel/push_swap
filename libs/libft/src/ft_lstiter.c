/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 16:32:56 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/10/29 11:45:11 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	if (lst == 0 || f == 0)
		return ;
	while (lst != 0)
	{
		if (lst->content != 0)
			(*f)(lst->content);
		lst = lst->next;
	}
}
