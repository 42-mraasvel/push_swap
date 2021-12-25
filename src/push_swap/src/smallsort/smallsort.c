/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   smallsort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/07 11:40:41 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 14:33:26 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "proto.h"
#include "smallsort.h"

static int	is_goal_state(t_state *state)
{
	int	i;

	if (state->size_a != state->total)
		return (false);
	i = 1;
	while (i < state->size_a)
	{
		if (state->table[i - 1] > state->table[i])
			return (false);
		i++;
	}
	return (true);
}

static void	expand_state(t_state *state, t_queue *queue, t_saves *saves)
{
	int		op;
	t_state	*new;

	op = 0;
	while (op < 11)
	{
		new = state_do_op(state, op);
		if (new != NULL)
		{
			if (saves_add(saves, new))
				queue_add(queue, new);
			else
				state_delete(new);
		}
		op++;
	}
}

static void	print_operations(t_state *state, t_data *data)
{
	t_ops	*ops;
	size_t	i;

	ops = ops_init(0);
	while (state->prev)
	{
		ops_pushback(ops, state->op);
		state = state->prev;
	}
	i = 0;
	while (i < ops->len)
	{
		do_op(data->a, data->b, ops->table[ops->len - i - 1], true);
		i++;
	}
	ops_delete(ops);
}

/*
** Sort for sizes <= 5
** Breadth First Tree search solution
**
** 1. Get initial state
** 2. Add state to queue (FIFO)
** 3. Pop top off the queue
** 4. Check if goal state
** 5. Expand state with all possible operations
** 6. Discard all states that have been achieved before
** 7. Add new states to queue and hash table
** 8. Repeat from step 3 until sorted state
**
** Finally free everything and print the operations that lead to the goal state
*/

int	smallsort(t_data *data)
{
	t_state	*state;
	t_queue	*queue;
	t_saves	*saves;

	queue = queue_init();
	saves = saves_init();
	state = original_state(data);
	queue_add(queue, state);
	saves_add(saves, state);
	while (!queue_empty(queue))
	{
		state = queue_pop(queue);
		if (is_goal_state(state))
			break ;
		expand_state(state, queue, saves);
	}
	print_operations(state, data);
	saves_delete(saves, state_delete_vp);
	queue_delete(queue, NULL);
	return (OK);
}
