/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bigsort.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/07 11:42:27 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/09 23:25:50 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "struct.h"
#include "libps.h"
#include "libft.h"
#include "proto.h"

/* Determines segment destination in splitting */
static t_target	get_target(t_stack *s, t_data *data)
{
	t_target	target;

	if (s == data->a)
	{
		target.bot_cur = 2;
		target.top_oth = 1;
		target.bot_oth = 0;
	}
	else
	{
		target.bot_cur = 0;
		target.top_oth = 2;
		target.bot_oth = 1;
	}
	return (target);
}

/* The segment with the largest unsorted integers */
static t_segment	*next_segment(t_list *segments)
{
	t_segment	*segment;

	segment = NULL;
	while (segments)
	{
		if (((t_segment *)(segments->content))->sorted)
			break ;
		segment = segments->content;
		segments = segments->next;
	}
	return (segment);
}

static int	split_choice(t_stack *s, t_target target, int segment, t_data *data)
{
	int		result;
	t_stack	*other;

	result = s->top->segment - segment;
	other = other_stack(s, data);
	if (result == target.bot_cur)
		ft_rotate(s, true);
	else if (result == target.top_oth)
		ft_push(other, s, true);
	else
	{
		ft_push(other, s, true);
		if (s->top && s->top->segment - segment == target.bot_cur)
		{
			do_op(data->a, data->b, rr, true);
			return (2);
		}
		else
			ft_rotate(other, true);
	}
	return (1);
}

/*
** Choices:
**	1. Find largest unsorted segment (largest in terms of index, not size)
**	2. If less than 20, sort to top of A
**	3. Rotate to the top of it's current segment if necessary
**	4. Split it into 3 parts based on the size
**	5. Largest onto A, smallest onto B etc
**	6. Repeat until sorted
*/

static void	next_choice(t_data *data, t_list *segments)
{
	t_segment	*seg;
	t_stack		*s;
	t_target	target;
	int			total;

	seg = next_segment(segments);
	if (seg->size < 20)
		segment_minsort(data, seg);
	else
	{
		s = segments_stack(data, seg->id);
		if (s->top->segment != seg->id)
			segment_rotate_top(s, seg->id, data);
		total = seg->size;
		target = get_target(s, data);
		segment_split(seg->id, segments, data);
		while (total > 0)
			total -= split_choice(s, target, seg->id, data);
	}
}

int	bigsort(t_data *data)
{
	t_list	*segments;

	segments = NULL;
	segment_insert(segment_new(0, 0, data->total - 1), &segments);
	while (!stack_isempty(data->b) || !stack_issorted(data->a))
		next_choice(data, segments);
	ft_lstclear(&segments, free);
	return (OK);
}
