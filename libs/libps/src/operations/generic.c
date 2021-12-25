/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   generic.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/06 22:03:33 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/10 10:48:55 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"
#include "libft.h"

int	ft_push(t_stack *dst, t_stack *src, int print)
{
	t_dlist	*entry;

	if (print)
	{
		if (dst->type == 'a')
			ft_putendl_fd("pa", STDOUT_FILENO);
		else if (dst->type == 'b')
			ft_putendl_fd("pb", STDOUT_FILENO);
	}
	if (stack_isempty(src))
		return (OK);
	entry = stack_pop(src);
	if (entry == NULL)
		return (OK);
	stack_push(dst, entry);
	return (OK);
}

int	ft_swap(t_stack *s, int print)
{
	if (print)
	{
		if (s->type == 'a')
			ft_putendl_fd("sa", STDOUT_FILENO);
		else if (s->type == 'b')
			ft_putendl_fd("sb", STDOUT_FILENO);
	}
	if (s == NULL || s->top == NULL || s->top->next == NULL)
		return (OK);
	ft_swapentry(s->top, s->top->next);
	return (OK);
}

int	ft_rotate(t_stack *s, int print)
{
	t_dlist	*tmp;

	if (print)
	{
		if (s->type == 'a')
			ft_putendl_fd("ra", STDOUT_FILENO);
		else if (s->type == 'b')
			ft_putendl_fd("rb", STDOUT_FILENO);
	}
	if (stack_isempty(s) || s->top == s->bot)
		return (OK);
	tmp = s->top;
	s->top = tmp->next;
	s->top->prev = NULL;
	tmp->prev = s->bot;
	tmp->next = NULL;
	s->bot->next = tmp;
	s->bot = tmp;
	return (OK);
}

int	ft_rrotate(t_stack *s, int print)
{
	t_dlist	*tmp;

	if (stack_isempty(s) || s->top == s->bot)
		return (OK);
	if (print)
	{
		if (s->type == 'a')
			ft_putendl_fd("rra", STDOUT_FILENO);
		else if (s->type == 'b')
			ft_putendl_fd("rrb", STDOUT_FILENO);
	}
	tmp = s->bot;
	s->bot = tmp->prev;
	s->bot->next = NULL;
	tmp->next = s->top;
	tmp->prev = NULL;
	s->top->prev = tmp;
	s->top = tmp;
	return (OK);
}
