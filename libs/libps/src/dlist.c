/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dlist.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/06 20:31:49 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/06 21:01:29 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libps.h"

/*
** Initializes both ints to data
*/

t_dlist	*dlist_create_elem(int data)
{
	t_dlist	*new;

	new = ft_malloc(1 * sizeof(t_dlist));
	new->data = data;
	new->rvalue = data;
	new->segment = 0;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	dlist_delete(t_dlist *start)
{
	t_dlist	*tmp;

	while (start != NULL)
	{
		tmp = start->next;
		free(start);
		start = tmp;
	}
}

int	dlist_prepend(t_dlist **start, int data)
{
	t_dlist	*tmp;

	if (start == NULL)
		return (-1);
	tmp = dlist_create_elem(data);
	if (*start == NULL)
		*start = tmp;
	else
	{
		tmp->next = *start;
		(*start)->prev = tmp;
		*start = tmp;
	}
	return (0);
}

int	dlist_append(t_dlist **end, int data)
{
	t_dlist	*tmp;

	if (end == NULL)
		return (-1);
	tmp = dlist_create_elem(data);
	if (*end == NULL)
		*end = tmp;
	else
	{
		tmp->prev = *end;
		(*end)->next = tmp;
		*end = tmp;
	}
	return (0);
}
