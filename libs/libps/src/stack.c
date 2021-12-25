/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 15:42:42 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/08 23:43:15 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <libft.h>
#include "libps.h"

t_stack	*stack_init(char type)
{
	t_stack	*new;

	new = ft_malloc(1 * sizeof(t_stack));
	ft_bzero(new, sizeof(t_stack));
	new->size = 0;
	new->type = type;
	return (new);
}

void	stack_delete(t_stack *s)
{
	if (s == NULL)
		return ;
	dlist_delete(s->top);
	free(s);
}

/* Will alocate new memory */
int	stack_append_new(t_stack **s, int data)
{
	if (*s == NULL)
		*s = stack_init('s');
	dlist_append(&(*s)->bot, data);
	if ((*s)->top == NULL)
		(*s)->top = (*s)->bot;
	(*s)->size += 1;
	return (0);
}

t_dlist	*stack_pop(t_stack *s)
{
	t_dlist	*tmp;

	if (stack_isempty(s))
		return (NULL);
	tmp = s->top;
	s->top = s->top->next;
	if (s->top == NULL)
		s->bot = NULL;
	else
		s->top->prev = NULL;
	s->size -= 1;
	return (tmp);
}

int	stack_push(t_stack *s, t_dlist *entry)
{
	entry->prev = NULL;
	entry->next = s->top;
	if (s->top != NULL)
		s->top->prev = entry;
	s->top = entry;
	if (s->bot == NULL)
		s->bot = s->top;
	else if (s->bot == s->top->next)
		s->bot->prev = entry;
	s->size += 1;
	return (0);
}
