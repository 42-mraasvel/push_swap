/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/11 09:19:23 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/11 09:37:51 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "libft.h"

static void	set_swap(t_data *data, t_printing *info, int op)
{
	if ((op == sa || op == ss) && data->a->size > 1)
	{
		info->last[0] = data->a->top;
		info->last[1] = data->a->top->next;
	}
	if ((op == sb || op == ss) && data->b->size > 1)
	{
		info->last[2] = data->b->top;
		info->last[3] = data->b->top->next;
	}
}

static void	set_push(t_data *data, t_printing *info, int op)
{
	if (op == pa && data->b->size != 0)
		info->last[0] = data->b->top;
	else if (op == pb && data->a->size != 0)
		info->last[0] = data->a->top;
}

static void	set_rotate(t_data *data, t_printing *info, int op)
{
	if ((op == ra || op == rr) && data->a->size != 0)
		info->last[0] = data->a->top;
	if ((op == rb || op == rr) && data->b->size != 0)
		info->last[1] = data->b->top;
}

static void	set_rrotate(t_data *data, t_printing *info, int op)
{
	if ((op == rra || op == rrr) && data->a->size != 0)
		info->last[0] = data->a->bot;
	if ((op == rrb || op == rrr) && data->b->size != 0)
		info->last[1] = data->b->bot;
}

void	set_color_ptr(t_data *data, t_printing *info, int op)
{
	ft_bzero(&info->last, sizeof(t_dlist *) * 4);
	if (op == sa || op == sb || op == ss)
		return (set_swap(data, info, op));
	else if (op == pa || op == pb)
		return (set_push(data, info, op));
	else if (op == ra || op == rb || op == rr)
		return (set_rotate(data, info, op));
	else
		return (set_rrotate(data, info, op));
}
