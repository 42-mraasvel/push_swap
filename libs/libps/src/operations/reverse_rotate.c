/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/06 21:49:36 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/06 21:50:38 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int	ft_rra(t_stack *a, t_stack *b)
{
	t_dlist	*tmp;

	if (stack_isempty(a) || a->top == a->bot)
		return (OK);
	tmp = a->bot;
	a->bot = tmp->prev;
	a->bot->next = NULL;
	tmp->next = a->top;
	tmp->prev = NULL;
	a->top->prev = tmp;
	a->top = tmp;
	(void)b;
	return (OK);
}

int	ft_rrb(t_stack *a, t_stack *b)
{
	t_dlist	*tmp;

	if (stack_isempty(b) || b->top == b->bot)
		return (OK);
	tmp = b->bot;
	b->bot = tmp->prev;
	b->bot->next = NULL;
	tmp->next = b->top;
	tmp->prev = NULL;
	b->top->prev = tmp;
	b->top = tmp;
	(void)a;
	return (OK);
}

int	ft_rrr(t_stack *a, t_stack *b)
{
	ft_rra(a, b);
	ft_rrb(a, b);
	return (OK);
}
