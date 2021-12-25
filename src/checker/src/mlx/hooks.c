/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/11 16:36:34 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/12 15:18:59 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "mlx.h"
#include "mlx_bonus.h"
#include "x_events.h"
#include "mlx_keys.h"
#include <stdio.h>

static void	update_delay(t_mlx *mlx, int dir)
{
	if (dir < 0)
		mlx->rdata.delay -= DELAY_INC;
	else
		mlx->rdata.delay += DELAY_INC;
	if (mlx->rdata.delay < MIN_DELAY)
		mlx->rdata.delay = MIN_DELAY;
	else if (mlx->rdata.delay > MAX_DELAY)
		mlx->rdata.delay = MAX_DELAY;
}

static int	close_window(t_mlx *mlx)
{
	end_mlx(mlx, OK);
	exit(EXIT_SUCCESS);
	return (OK);
}

static int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == K_ESC)
		close_window(mlx);
	else if (keycode == K_ENTER && mlx->rdata.active == false)
	{
		mlx->rdata.active = true;
		if (execute_operations(mlx) == ERROR)
		{
			ft_perror("pthread");
			close_window(mlx);
		}
	}
	else if (keycode == K_AR_L)
		update_delay(mlx, 1);
	else if (keycode == K_AR_R)
		update_delay(mlx, -1);
	else if (keycode == K_P)
		mlx->rdata.paused = ~(mlx->rdata.paused);
	else if (keycode == K_SP && mlx->rdata.paused)
		mlx->rdata.next = true;
	return (OK);
}

#ifdef __APPLE__

void	activate_hooks(t_mlx *mlx)
{
	mlx_key_hook(mlx->win_ptr, key_hook, mlx);
	mlx_hook(mlx->win_ptr,
		DESTROYNOTIFY, NOEVENTMASK, close_window, mlx);
}

#else

void	activate_hooks(t_mlx *mlx)
{
	mlx_key_hook(mlx->win_ptr, key_hook, mlx);
	mlx_hook(mlx->win_ptr, CLIENTMESSAGE, NOEVENTMASK, close_window, mlx);
}

#endif
