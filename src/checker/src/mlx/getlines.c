/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   getlines.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/12 14:18:44 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 18:03:33 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx_bonus.h"
#include <stdio.h>

static t_line	calculate_line(int data, t_box a, int total)
{
	float	percent;
	t_line	line;

	percent = (float)(data + 1) / (float)total;
	line.col = gradient_rb(percent);
	if (total >= a.width)
		line.width = 1;
	else
		line.width = a.width / total;
	line.height = percent * (float)a.height;
	return (line);
}

t_line	*getlines(t_mlx *mlx, t_scene *scene)
{
	t_line	*lines;
	t_dlist	*top;
	int		i;

	lines = ft_malloc(mlx->rdata.data->total * sizeof(t_line));
	top = mlx->rdata.data->a->top;
	i = 0;
	while (top)
	{
		lines[top->data] = calculate_line(top->data,
				scene->a, mlx->rdata.data->total);
		top = top->next;
		i++;
	}
	return (lines);
}
