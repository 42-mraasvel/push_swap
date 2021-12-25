/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/06 21:50:23 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/06 21:50:42 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int	ft_ra(t_stack *a, t_stack *b)
{
	t_dlist	*tmp;

	if (stack_isempty(a) || a->top == a->bot)
		return (OK);
	tmp = a->top;
	a->top = tmp->next;
	a->top->prev = NULL;
	tmp->prev = a->bot;
	tmp->next = NULL;
	a->bot->next = tmp;
	a->bot = tmp;
	(void)b;
	return (OK);
}

int	ft_rb(t_stack *a, t_stack *b)
{
	t_dlist	*tmp;

	if (stack_isempty(b) || b->top == b->bot)
		return (OK);
	tmp = b->top;
	b->top = tmp->next;
	b->top->prev = NULL;
	tmp->prev = b->bot;
	tmp->next = NULL;
	b->bot->next = tmp;
	b->bot = tmp;
	(void)a;
	return (OK);
}

int	ft_rr(t_stack *a, t_stack *b)
{
	ft_ra(a, b);
	ft_rb(a, b);
	return (OK);
}
