/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/11 17:00:20 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 20:49:40 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "mlx_bonus.h"
#include "libft.h"

static void	render_state(t_mlx *mlx, t_img *img)
{
	draw_stack(img, mlx->rdata.data->a, mlx->rdata.scene->a, mlx->rdata.scene);
	draw_stack(img, mlx->rdata.data->b, mlx->rdata.scene->b, mlx->rdata.scene);
}

/* Renders frame into img2 */
int	render_frame(t_mlx *mlx, t_img *img)
{
	if (mlx->rdata.finished == true)
	{
		if (stack_isempty(mlx->rdata.data->b)
			&& stack_issorted(mlx->rdata.data->a))
			ft_putstr_fd("OK\n", STDOUT_FILENO);
		else
			ft_putstr_fd("KO\n", STDOUT_FILENO);
	}
	ft_bzero(img->addr, img->size_line * mlx->wdata.winy);
	render_state(mlx, img);
	mlx->rdata.changed = false;
	usleep(mlx->rdata.delay);
	return (OK);
}
