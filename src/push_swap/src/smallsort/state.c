/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/09 08:55:56 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/09 23:07:00 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "smallsort.h"

void	state_delete(t_state *state)
{
	if (!state)
		return ;
	free(state->table);
	free(state);
}

void	state_delete_vp(void *state)
{
	state_delete(state);
}

/* True if equal, false if unequal */
int	state_cmp(t_state *a, t_state *b)
{
	if (a->size_a != b->size_a)
		return (false);
	if (ft_memcmp(a->table, b->table, a->total) != 0)
		return (false);
	return (true);
}

t_state	*state_new(t_state *prev, char size_a, char *table, char op)
{
	t_state	*new;

	new = ft_malloc(1 * sizeof(t_state));
	new->prev = prev;
	new->size_a = size_a;
	new->table = table;
	new->op = op;
	new->total = prev->total;
	return (new);
}

/*
** Copy the original state of A into a more memory efficient variant
*/
t_state	*original_state(t_data *data)
{
	t_state	*new;
	t_dlist	*cur;
	int		i;

	new = ft_malloc(1 * sizeof(t_state));
	new->op = -1;
	new->prev = NULL;
	new->size_a = data->total;
	new->total = data->total;
	new->table = ft_malloc (new->total * sizeof(char));
	cur = data->a->top;
	i = 0;
	while (cur)
	{
		new->table[i] = (char)cur->data;
		cur = cur->next;
		i++;
	}
	return (new);
}
