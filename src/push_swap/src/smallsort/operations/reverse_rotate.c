/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/09 10:00:20 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 14:32:11 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "smallsort.h"

void	state_rra(t_state *state, char *new)
{
	ft_memcpy(new + 1, state->table, state->size_a - 1);
	new[0] = state->table[(int)(state->size_a - 1)];
	ft_memcpy(new + state->size_a,
		state->table + state->size_a, state->total - state->size_a);
}

void	state_rrb(t_state *state, char *new)
{
	ft_memcpy(new, state->table, state->size_a);
	ft_memcpy(new + state->size_a + 1,
		state->table + state->size_a, state->total - state->size_a - 1);
	new[(int)state->size_a] = state->table[(int)(state->total - 1)];
}

void	state_rrr(t_state *state, char *new)
{
	ft_memcpy(new + 1, state->table, state->size_a - 1);
	new[0] = state->table[(int)(state->size_a - 1)];
	ft_memcpy(new + state->size_a + 1,
		state->table + state->size_a, state->total - state->size_a - 1);
	new[(int)state->size_a] = state->table[(int)(state->total - 1)];
}
