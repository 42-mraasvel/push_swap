/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/07 11:46:48 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/07 11:47:24 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libps.h"

int	stack_isempty(t_stack *s)
{
	if (s == NULL || s->top == NULL)
		return (true);
	return (false);
}

int	stack_issorted(t_stack *s)
{
	t_dlist	*cur;
	int		prev;

	cur = s->top;
	while (cur != NULL)
	{
		prev = cur->data;
		cur = cur->next;
		if (cur == NULL)
			break ;
		if (prev > cur->data)
			return (false);
	}
	return (true);
}
