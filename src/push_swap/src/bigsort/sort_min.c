/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_min.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/09 08:04:17 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/09 23:30:39 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "struct.h"
#include "libps.h"

/*
** Returns:
**	0 = rotate
**	1 = reverse rotate
*/

static int	find_num(t_stack *s, int num)
{
	t_dlist	*top;
	t_dlist	*bot;

	top = s->top;
	bot = s->bot;
	while (top != bot)
	{
		if (top->data == num)
			return (0);
		else if (bot->data == num)
			return (1);
		top = top->next;
		bot = bot->prev;
	}
	return (0);
}

static void	segment_insertion_a(t_data *data, t_segment *seg)
{
	int	num;
	int	op;

	num = seg->max;
	while (num >= seg->min)
	{
		op = find_num(data->b, num);
		while (data->b->top->data != num)
		{
			if (op == 0)
				do_op(data->a, data->b, rb, true);
			else
				do_op(data->a, data->b, rrb, true);
		}
		do_op(data->a, data->b, pa, true);
		num--;
	}
}

static void	segment_insertion_b(t_data *data, t_segment *seg)
{
	int	num;
	int	op;

	num = seg->min;
	while (num <= seg->max)
	{
		op = find_num(data->a, num);
		while (data->a->top->data != num)
		{
			if (op == 0)
				do_op(data->a, data->b, ra, true);
			else
				do_op(data->a, data->b, rra, true);
		}
		do_op(data->a, data->b, pb, true);
		num++;
	}
	while (data->b->size > 0 && data->b->top->segment == seg->id)
		do_op(data->a, data->b, pa, true);
}

/*
** 4 Options:
**	1. Top of A
**	2. Bot of A
**	3. Top of B
**	4. Bot of B
*/

void	segment_minsort(t_data *data, t_segment *seg)
{
	seg->sorted = true;
	if (data->b->size > 0 && (data->b->top->segment == seg->id
			|| data->b->bot->segment == seg->id))
		segment_insertion_a(data, seg);
	else
		segment_insertion_b(data, seg);
}
