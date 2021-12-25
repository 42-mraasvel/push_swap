/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/06 21:58:15 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/06 22:01:41 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "libps.h"

static int	execute_ops(t_stack *a, t_stack *b, t_optype type)
{
	static t_operation	operations[] = {
		ft_sa,
		ft_sb,
		ft_ss,
		ft_pa,
		ft_pb,
		ft_ra,
		ft_rb,
		ft_rr,
		ft_rra,
		ft_rrb,
		ft_rrr
	};

	if (operations[type] == NULL)
		return (ft_error(NULL, "Unsupported Operation"));
	operations[type](a, b);
	return (OK);
}

char	*get_op_str(t_optype op)
{
	static char	*ops[] = {
		"sa",
		"sb",
		"ss",
		"pa",
		"pb",
		"ra",
		"rb",
		"rr",
		"rra",
		"rrb",
		"rrr",
		NULL
	};

	return (ops[op]);
}

/* Return inversion of operation */
t_optype	invert_op(t_optype op)
{
	static t_optype	invert[] = {
		sa,
		sb,
		ss,
		pb,
		pa,
		rra,
		rrb,
		rrr,
		ra,
		rb,
		rr
	};

	return (invert[op]);
}

t_optype	combined_op(t_optype op)
{
	if (op == sa || op == sb)
		return (ss);
	else if (op == ra || op == rb)
		return (rr);
	else if (op == rra || op == rrb)
		return (rrr);
	return (op);
}

int	do_op(t_stack *a, t_stack *b, t_optype op, int print)
{
	if (print)
		ft_putendl_fd(get_op_str(op), STDOUT_FILENO);
	return (execute_ops(a, b, op));
}
