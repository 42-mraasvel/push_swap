/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_mlx.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/11 14:21:58 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 17:55:58 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include "mlx_bonus.h"
#include "mlx.h"
#include "libft.h"

static void	ps_swap_ptr(void *a, void *b)
{
	void	*temp;

	temp = *(void **)a;
	*(void **)a = *(void **)b;
	*(void **)b = temp;
}

int	renderer(t_mlx *mlx)
{
	if (mlx->rdata.changed)
	{
		render_frame(mlx, mlx->img2);
		mlx_put_image_to_window(mlx->mlx_ptr,
			mlx->win_ptr, mlx->img2->img_ptr, 0, 0);
		ps_swap_ptr(&mlx->img1, &mlx->img2);
	}
	return (OK);
}

int	execute_mlx(t_data *data)
{
	t_mlx	mlx;

	if (init_viz(&mlx) == ERROR)
		return (end_mlx(&mlx, ERROR));
	mlx.rdata.data = data;
	mlx.rdata.delay = (1.f - (float)data->total / 100.f) * MAX_DELAY;
	if (mlx.rdata.delay < MIN_DELAY)
		mlx.rdata.delay = MIN_DELAY;
	mlx.rdata.scene = scene_init(&mlx);
	activate_hooks(&mlx);
	mlx.rdata.changed = true;
	renderer(&mlx);
	mlx.rdata.changed = false;
	mlx_loop_hook(mlx.mlx_ptr, renderer, &mlx);
	mlx_loop(mlx.mlx_ptr);
	end_mlx(&mlx, OK);
	return (OK);
}
