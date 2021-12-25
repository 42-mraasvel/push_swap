/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/12 14:31:29 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 20:49:07 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_bonus.h"

void	draw_box(t_img *img, t_box box)
{
	int		w;
	int		h;
	t_col	col;

	w = 0;
	col = col_gen(255, 255, 255);
	while (w < box.width)
	{
		ft_pixelput(img, box.botright.x + w, box.botright.y, col);
		ft_pixelput(img, box.botright.x + w, box.botright.y - box.height, col);
		w++;
	}
	h = 0;
	while (h < box.height)
	{
		ft_pixelput(img, box.botright.x, box.botright.y - h, col);
		ft_pixelput(img, box.botright.x + box.width, box.botright.y - h, col);
		h++;
	}
}

void	draw_line(t_img *img, t_line line)
{
	int	i;
	int	j;

	i = 0;
	while (i < line.height)
	{
		j = 0;
		while (j < line.width)
		{
			ft_pixelput(img, line.start.x + j, line.start.y - i, line.col);
			j++;
		}
		i++;
	}
}

void	draw_stack(t_img *img, t_stack *s, t_box b, t_scene *scene)
{
	int		x;
	int		y;
	t_dlist	*top;

	y = 0;
	top = s->top;
	while (y < b.height && top)
	{
		x = 0;
		while (x < b.width && top)
		{
			scene->lines[top->data].start.x
				= b.botright.x + x * scene->lines[top->data].width;
			scene->lines[top->data].start.y = b.botright.y;
			draw_line(img, scene->lines[top->data]);
			top = top->next;
			x++;
		}
		y++;
	}
}
