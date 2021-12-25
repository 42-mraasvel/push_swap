/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_wrapper.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/11 16:37:33 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/12 14:02:00 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_bonus.h"

void	ft_pixelput(t_img *img, int x, int y, t_col color)
{
	char	*addr;
	int		index;

	if (x >= img->w || y >= img->h || x < 0 || y < 0)
		return ;
	index = (y * img->size_line) + x * (img->bpp / 8);
	addr = img->addr + index;
	*(unsigned int *)addr = color.col;
}
