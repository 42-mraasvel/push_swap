/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_ops.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/11 17:04:12 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/12 15:16:23 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_bonus.h"
#include <stdbool.h>
#include <pthread.h>
#include <stdio.h>

static void	*thread_operations(void *param)
{
	t_rdata	*rdata;
	size_t	i;

	rdata = param;
	i = 0;
	while (i < rdata->data->ops->len)
	{
		while (rdata->changed == true)
		{
			if (rdata->quit_request == true)
				return (NULL);
		}
		while (rdata->paused && rdata->next == false)
			;
		do_op(rdata->data->a,
			rdata->data->b, rdata->data->ops->table[i], false);
		i++;
		rdata->changed = true;
		rdata->next = false;
	}
	rdata->finished = true;
	return (NULL);
}

int	execute_operations(t_mlx *mlx)
{
	pthread_t	id;

	if (pthread_create(&id, NULL, thread_operations, &mlx->rdata) != 0)
	{
		return (ERROR);
	}
	mlx->rdata.ptid = id;
	return (OK);
}
