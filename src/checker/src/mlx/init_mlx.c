/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_mlx.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/11 15:27:27 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/14 08:11:14 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_bonus.h"
#include "libft.h"
#include "mlx.h"

static void	get_resolution(t_mlx *mlx)
{
	int	x;
	int	y;

	mlx_get_screen_size(mlx->mlx_ptr, &x, &y);
	mlx->wdata.winx = ft_min(x, WINX);
	mlx->wdata.winy = ft_min(y, WINY);
}

static int	get_image(t_mlx *mlx, t_img **img)
{
	*img = ft_calloc(1, sizeof(t_img));
	(*img)->img_ptr = mlx_new_image(mlx->mlx_ptr,
			mlx->wdata.winx, mlx->wdata.winy);
	if ((*img)->img_ptr == NULL)
		return (ERROR);
	(*img)->addr = mlx_get_data_addr((*img)->img_ptr, &(*img)->bpp,
			&(*img)->size_line, &(*img)->endian);
	if ((*img)->addr == NULL)
		return (ERROR);
	(*img)->w = mlx->wdata.winx;
	(*img)->h = mlx->wdata.winy;
	return (OK);
}

int	init_viz(t_mlx *mlx)
{
	ft_bzero(mlx, sizeof(t_mlx));
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		return (ft_error("MLX: ", "failed to initialize"));
	get_resolution(mlx);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr,
			mlx->wdata.winx, mlx->wdata.winy, "Push Swap");
	if (mlx->win_ptr == NULL)
		return (ERROR);
	if (get_image(mlx, &mlx->img1) == ERROR)
		return (ERROR);
	if (get_image(mlx, &mlx->img2) == ERROR)
		return (ERROR);
	return (OK);
}
