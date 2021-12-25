/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_operations.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/06 22:22:41 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/10 09:00:32 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "libps.h"

static int	get_op(char *op)
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
	size_t		i;

	i = 0;
	while (ops[i] != NULL)
	{
		if (ft_strcmp(op, ops[i]) == 0)
			return (i);
		i++;
	}
	return (ERROR);
}

static int	process_line(t_ops *ops, char *line)
{
	int	type;

	type = get_op(line);
	if (type == ERROR)
		return (ft_error("Invalid Operation: ", line));
	ops_pushback(ops, (t_optype)type);
	return (OK);
}

/*
** Read operations / instructions from file descriptor
** Store operations in the ops pointer
*/
int	parse_ops(t_ops *ops, int fd)
{
	char	*line;
	int		ret;
	int		result;

	ret = 1;
	result = OK;
	while (ret > 0)
	{
		ret = ft_getline(fd, &line);
		if (ret == -1)
			return (ft_error(NULL, "Error reading operations\n"));
		if (ret != 0)
			if (process_line(ops, line) == ERROR)
				result = ERROR;
		free(line);
		if (result == ERROR)
			return (ERROR);
	}
	return (OK);
}
