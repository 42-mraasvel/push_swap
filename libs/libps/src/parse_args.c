/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_args.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/06 20:37:30 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/08 10:31:00 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "libft.h"
#include "libps.h"

/*
** Simple check for valid integer
** Above functions are obsolete
** But they may be slightly better / faster
*/

static int	validarg(char *arg)
{
	int		result;
	char	*checker;

	result = ft_atoi(arg);
	checker = oom_guard(ft_itoa(result));
	result = true;
	if (ft_strcmp(checker, arg) != 0)
		result = false;
	free(checker);
	return (result);
}

static int	instack(t_stack *stack, int data)
{
	t_dlist	*cur;

	if (stack == NULL)
		return (false);
	cur = stack->top;
	while (cur != NULL)
	{
		if (cur->data == data)
			return (true);
		cur = cur->next;
	}
	return (false);
}

/*
** Start parsing at index start (for future flags for example)
** If 0: start at 1 because of argc;
** return value is the total number of integers parsed
** -1 on error
*/
int	parse_args(int argc, char *argv[], int start, t_stack **dst)
{
	int		val;
	int		total;

	if (start == 0)
		start = 1;
	total = 0;
	while (start < argc)
	{
		if (!validarg(argv[start]))
			return (ft_error("Invalid argument: ", argv[start]));
		val = ft_atoi(argv[start]);
		if (instack(*dst, val))
			return (ft_error("Duplicate Argument: ", argv[start]));
		stack_append_new(dst, val);
		start++;
		total++;
	}
	return (total);
}
