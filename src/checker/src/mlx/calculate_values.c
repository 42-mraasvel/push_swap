/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calculate_values.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/12 14:11:16 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 17:56:03 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_bonus.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static t_box	get_boxa(t_mlx *mlx)
{
	t_box	a;

	a.width = mlx->wdata.winx / 2 - 10;
	a.height = mlx->wdata.winy * 3 / 4;
	a.botright.x = 1;
	a.botright.y = mlx->wdata.winy - 1;
	return (a);
}

static t_box	get_boxb(t_mlx *mlx)
{
	t_box	b;

	b.width = mlx->wdata.winx / 2 - 10;
	b.height = mlx->wdata.winy * 3 / 4;
	b.botright.y = mlx->wdata.winy - 1;
	b.botright.x = mlx->wdata.winx / 2;
	return (b);
}

t_scene	*scene_init(t_mlx *mlx)
{
	t_scene	*scene;

	scene = ft_malloc(1 * sizeof(t_scene));
	ft_bzero(scene, sizeof(t_scene));
	scene->a = get_boxa(mlx);
	scene->b = get_boxb(mlx);
	scene->lines = getlines(mlx, scene);
	return (scene);
}

void	scene_destroy(t_scene *scene)
{
	if (!scene)
		return ;
	free(scene->lines);
	free(scene);
}
