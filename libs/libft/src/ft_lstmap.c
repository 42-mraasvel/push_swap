/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 16:35:05 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 11:51:31 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*start;
	t_list	*new;

	if (lst == 0 || f == 0 || del == 0)
		return (0);
	start = 0;
	while (lst != 0)
	{
		new = ft_lstnew((*f)(lst->content));
		if (new == 0)
		{
			ft_lstclear(&start, del);
			return (0);
		}
		if (new->content == 0)
			ft_lstdelone(new, (void *) 0);
		else
			ft_lstadd_back(&start, new);
		lst = lst->next;
	}
	return (start);
}
