/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state_ops.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/09 09:02:29 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 14:33:08 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "smallsort.h"
#include "libps.h"

static void	state_expand(t_state *prev, char op, char *new)
{
	static t_state_op	ops[] = {
		state_sa,
		state_sb,
		state_ss,
		state_pa,
		state_pb,
		state_ra,
		state_rb,
		state_rr,
		state_rra,
		state_rrb,
		state_rrr
	};

	ops[(int)op](prev, new);
}

static int	pointless_operation(t_state *state, char op)
{
	char	size_b;

	size_b = state->total - state->size_a;
	if ((op == sa || op == ra || op == rra) && state->size_a <= 1)
		return (true);
	else if ((op == sb || op == rb || op == rrb) && size_b <= 1)
		return (true);
	else if (op == pa && size_b == 0)
		return (true);
	else if (op == pb && state->size_a == 0)
		return (true);
	else if ((state->size_a <= 1 || size_b <= 1)
		&& (op == ss || op == rr || op == rrr))
		return (true);
	return (false);
}

t_state	*state_do_op(t_state *prev, char op)
{
	char	*newtable;
	char	size_a;

	if (pointless_operation(prev, op))
		return (NULL);
	size_a = prev->size_a;
	newtable = ft_malloc(prev->total * sizeof(char));
	state_expand(prev, op, newtable);
	if (op == pb && size_a != 0)
		size_a -= 1;
	else if (op == pa && prev->total != size_a)
		size_a += 1;
	return (state_new(prev, size_a, newtable, op));
}
