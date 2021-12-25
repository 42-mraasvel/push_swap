/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/11 17:30:58 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 17:14:09 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mlx_bonus.h"

t_col	col_gen(int r, int g, int b)
{
	t_col	color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.t = 0;
	return (color);
}

t_col	col_scale(t_col col, float f)
{
	t_col	new;

	new = col_gen((f * (float)col.r), f * (float)col.g, f * (float)col.b);
	return (new);
}

static float	compute_gradient(float percent)
{
	return (sqrtf((percent * 255 * 255)));
}

t_col	gradient_rb(float percent)
{
	return (col_gen(compute_gradient(percent),
			70, compute_gradient(1.f - percent)));
}
