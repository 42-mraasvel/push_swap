/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   segment_split.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/08 21:49:21 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 14:29:03 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"
#include "libft.h"
#include "struct.h"

/* Next segment IDs should be incremented by 2, because we split in 3 */
static void	update_next_segments(t_list *segments)
{
	t_segment	*segment;

	while (segments)
	{
		segment = segments->content;
		segment->id += 2;
		segments = segments->next;
	}
}

/* Update all segments in the stacks after a split */
static void	update_segments(t_list *segments, t_data *data)
{
	int			i;
	t_segment	*segment;

	i = 0;
	while (segments)
	{
		segment = segments->content;
		while (i < data->total && ft_isseg(data->sorted_ptrs[i]->data, segment))
		{
			data->sorted_ptrs[i]->segment = segment->id;
			i++;
		}
		segments = segments->next;
	}
}

/*
** Split segment into even groups of 3:
**	6 : 2 - 2 - 2
**	7 : 3 - 2 - 2
**	8 : 3 - 3 - 2
*/

static void	new_segments(t_data *data, t_segment *original, t_list *segments)
{
	t_segment	*two;
	t_segment	*three;
	int			remainder;

	remainder = original->size % 3;
	three = segment_new(original->id + 2,
			original->max - (original->size / 3 - 1), original->max);
	if (remainder == 2)
		two = segment_new(original->id + 1,
				three->min - 2 - (original->size / 3 - 1), three->min - 1);
	else
		two = segment_new(original->id + 1,
				three->min - 1 - (original->size / 3 - 1), three->min - 1);
	original->max = two->min - 1;
	original->size = original->max - original->min + 1;
	segment_insert(two, &segments);
	segment_insert(three, &segments);
	(void)data;
}

/*
** 1. Update segments after current segment in the list
** 2. Create 2 new segments and update the ranges
** 3. Update all segments in the stacks to the new values
*/

void	segment_split(int seg, t_list *segments, t_data *data)
{
	t_list	*start;

	start = segments;
	while (((t_segment *)(segments->content))->id != seg)
		segments = segments->next;
	update_next_segments(segments->next);
	new_segments(data, segments->content, segments);
	update_segments(start, data);
}
