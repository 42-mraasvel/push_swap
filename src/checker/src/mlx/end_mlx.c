/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   end_mlx.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/11 15:37:46 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 20:49:26 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "mlx.h"
#include "mlx_bonus.h"
#include <pthread.h>

static void	destroy_image(t_mlx *mlx, t_img *img)
{
	if (img == NULL)
		return ;
	if (img->img_ptr != NULL)
		mlx_destroy_image(mlx->mlx_ptr, img->img_ptr);
	free(img);
}

#ifdef __APPLE__

static void	free_mlx(t_mlx *mlx)
{
	if (mlx->win_ptr != NULL)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
}

#else

static void	free_mlx(t_mlx *mlx)
{
	if (mlx->mlx_ptr != NULL)
		mlx_destroy_display(mlx->mlx_ptr);
	if (mlx->win_ptr != NULL)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	free(mlx->mlx_ptr);
}

#endif

int	end_mlx(t_mlx *mlx, int status)
{
	if (mlx->mlx_ptr == NULL)
		return (status);
	if (status == ERROR)
		ft_error("MLX: ", "error");
	if (mlx->rdata.ptid)
	{
		mlx->rdata.quit_request = true;
		pthread_join(mlx->rdata.ptid, NULL);
	}
	scene_destroy(mlx->rdata.scene);
	destroy_image(mlx, mlx->img1);
	destroy_image(mlx, mlx->img2);
	free_mlx(mlx);
	return (status);
}
