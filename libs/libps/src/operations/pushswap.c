/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushswap.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/06 21:51:09 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/10 10:49:44 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int	ft_sa(t_stack *a, t_stack *b)
{
	if (a == NULL || a->top == NULL || a->top->next == NULL)
		return (OK);
	ft_swapentry(a->top, a->top->next);
	(void)b;
	return (OK);
}

int	ft_sb(t_stack *a, t_stack *b)
{
	if (b == NULL || b->top == NULL || b->top->next == NULL)
		return (OK);
	ft_swapentry(b->top, b->top->next);
	(void)a;
	return (OK);
}

int	ft_ss(t_stack *a, t_stack *b)
{
	ft_sa(a, b);
	ft_sb(a, b);
	return (OK);
}

int	ft_pa(t_stack *a, t_stack *b)
{
	t_dlist	*entry;

	if (stack_isempty(b))
		return (OK);
	entry = stack_pop(b);
	if (entry == NULL)
		return (OK);
	stack_push(a, entry);
	return (OK);
}

int	ft_pb(t_stack *a, t_stack *b)
{
	t_dlist	*entry;

	if (stack_isempty(a))
		return (OK);
	entry = stack_pop(a);
	if (entry == NULL)
		return (OK);
	stack_push(b, entry);
	return (OK);
}
