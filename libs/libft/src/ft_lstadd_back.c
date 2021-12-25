/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_listadd_back_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 14:54:42 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/10/28 18:32:32 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*findend;

	if (lst == 0 || new == 0)
		return ;
	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	findend = *lst;
	while (findend->next != 0)
		findend = findend->next;
	findend->next = new;
}
