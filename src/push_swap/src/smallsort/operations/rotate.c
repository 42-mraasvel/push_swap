/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/09 10:00:05 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 14:32:48 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "smallsort.h"

void	state_ra(t_state *state, char *new)
{
	ft_memcpy(new, state->table + 1, state->size_a - 1);
	new[(int)(state->size_a - 1)] = state->table[0];
	ft_memcpy(new + state->size_a,
		state->table + state->size_a, state->total - state->size_a);
}

void	state_rb(t_state *state, char *new)
{
	ft_memcpy(new, state->table, state->size_a);
	ft_memcpy(new + state->size_a,
		state->table + state->size_a + 1, state->total - state->size_a - 1);
	new[(int)(state->total - 1)] = state->table[(int)state->size_a];
}

void	state_rr(t_state *state, char *new)
{
	ft_memcpy(new, state->table + 1, state->size_a - 1);
	new[(int)(state->size_a - 1)] = state->table[0];
	ft_memcpy(new + state->size_a,
		state->table + state->size_a + 1, state->total - state->size_a - 1);
	new[(int)(state->total - 1)] = state->table[(int)state->size_a];
}
