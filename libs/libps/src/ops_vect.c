/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ops_vect.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/06 22:36:12 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/10 08:16:52 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "libps.h"

/*
** Vector specifically for saving operations
*/

t_ops	*ops_init(size_t initial_size)
{
	t_ops	*new;

	if (initial_size == 0)
		initial_size = 10;
	new = ft_malloc(1 * sizeof(t_ops));
	new->table = ft_malloc(initial_size * sizeof(t_ops));
	new->size = initial_size;
	new->len = 0;
	return (new);
}

void	ops_delete(t_ops *ops)
{
	if (!ops)
		return ;
	free(ops->table);
	free(ops);
}

int	ops_realloc(t_ops *ops)
{
	t_optype	*new_table;

	ops->size *= 2;
	new_table = ft_malloc(ops->size * sizeof(t_ops));
	ft_memcpy(new_table, ops->table, ops->len * sizeof(t_ops));
	free(ops->table);
	ops->table = new_table;
	return (0);
}

int	ops_pushback(t_ops *ops, t_optype type)
{
	if (ops->len == ops->size)
		if (ops_realloc(ops) == ERROR)
			return (ERROR);
	ops->table[ops->len] = type;
	ops->len += 1;
	return (0);
}

t_optype	ops_get(t_ops *ops, size_t index)
{
	return (ops->table[index]);
}
