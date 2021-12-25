/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   visualize.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/10 10:21:43 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 16:54:51 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "checker.h"

int	execute(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->ops->len)
	{
		do_op(data->a, data->b, data->ops->table[i], false);
		i++;
	}
	return (OK);
}
