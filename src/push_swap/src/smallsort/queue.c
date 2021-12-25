/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   queue.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/09 10:13:14 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/09 10:19:44 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "smallsort.h"

t_queue	*queue_init(void)
{
	t_queue	*new;

	new = ft_malloc(1 * sizeof(t_queue));
	new->end = NULL;
	new->start = NULL;
	return (new);
}

void	queue_delete(t_queue *queue, void (*del)(void *))
{
	ft_lstclear(&queue->start, del);
	free(queue);
}

void	queue_add(t_queue *queue, void *data)
{
	if (queue->start == NULL)
	{
		queue->start = oom_guard(ft_lstnew(data));
		queue->end = queue->start;
	}
	else
	{
		queue->end->next = oom_guard(ft_lstnew(data));
		queue->end = queue->end->next;
	}
}

void	*queue_pop(t_queue *queue)
{
	void	*data;
	t_list	*temp;

	data = queue->start->content;
	temp = queue->start;
	queue->start = queue->start->next;
	ft_lstdelone(temp, NULL);
	return (data);
}

int	queue_empty(t_queue *queue)
{
	if (queue->start == NULL)
		return (true);
	return (false);
}
