/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   segment_util.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/08 21:25:43 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 14:28:44 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"
#include "struct.h"

t_segment	*segment_new(int id, int min, int max)
{
	t_segment	*new;

	new = ft_malloc(1 * sizeof(t_segment));
	new->id = id;
	new->min = min;
	new->max = max;
	new->size = max - min + 1;
	new->sorted = false;
	return (new);
}

void	segment_insert(t_segment *new, t_list **list)
{
	t_list	*cur;
	t_list	*temp;

	if (*list == NULL)
		*list = oom_guard(ft_lstnew(new));
	else
	{
		cur = *list;
		while (cur->next)
		{
			if (new->id < ((t_segment *)(cur->next->content))->id)
				break ;
			cur = cur->next;
		}
		temp = cur->next;
		cur->next = oom_guard(ft_lstnew(new));
		cur->next->next = temp;
	}
}

t_stack	*segments_stack(t_data *data, int segment)
{
	t_dlist	*cur;

	cur = data->a->top;
	while (cur)
	{
		if (cur->segment == segment)
			return (data->a);
		cur = cur->next;
	}
	return (data->b);
}

void	segment_rotate_top(t_stack *s, int segment, t_data *data)
{
	if (s->top->segment == segment)
		return ;
	while (s->bot->segment == segment)
		ft_rrotate(s, true);
	(void)data;
}

t_stack	*other_stack(t_stack *s, t_data *data)
{
	if (s == data->a)
		return (data->b);
	return (data->a);
}
