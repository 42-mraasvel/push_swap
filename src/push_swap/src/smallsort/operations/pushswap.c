/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushswap.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/09 09:59:54 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 14:31:17 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "smallsort.h"

void	state_sa(t_state *state, char *new)
{
	char	temp;

	ft_memcpy(new, state->table, state->total);
	temp = new[0];
	new[0] = new[1];
	new[1] = temp;
}

void	state_sb(t_state *state, char *new)
{
	char	temp;

	ft_memcpy(new, state->table, state->total);
	temp = new[(int)state->size_a];
	new[(int)(state->size_a)] = new[(int)(state->size_a + 1)];
	new[(int)(state->size_a + 1)] = temp;
}

void	state_ss(t_state *state, char *new)
{
	char	temp;

	ft_memcpy(new, state->table, state->total);
	temp = new[0];
	new[0] = new[1];
	new[1] = temp;
	temp = new[(int)(state->size_a)];
	new[(int)(state->size_a)] = new[(int)(state->size_a + 1)];
	new[(int)(state->size_a + 1)] = temp;
}

void	state_pa(t_state *state, char *new)
{
	ft_memcpy(new + 1, state->table, state->size_a);
	new[0] = state->table[(int)state->size_a];
	ft_memcpy(new + state->size_a + 1,
		state->table + state->size_a + 1, state->total - state->size_a - 1);
}

void	state_pb(t_state *state, char *new)
{
	ft_memcpy(new, state->table + 1, state->size_a - 1);
	new[state->size_a - 1] = state->table[0];
	ft_memcpy(new + state->size_a,
		state->table + state->size_a, state->total - state->size_a);
}
