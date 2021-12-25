/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   btree.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/07 14:45:23 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/08 10:54:06 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"
#include <stdlib.h>

t_btree	*btree_new(void *data)
{
	t_btree	*new;

	new = ft_malloc(1 * sizeof(t_btree));
	new->right = NULL;
	new->left = NULL;
	new->data = data;
	return (new);
}

void	btree_delete(t_btree *btree, void (*del)(void *))
{
	if (btree == NULL)
		return ;
	btree_delete(btree->left, del);
	btree_delete(btree->right, del);
	if (del)
		del(btree->data);
	free(btree);
}

/*
** cmp(a, b)
** if cmp == true: a has priority over b
** and will be considered smaller (thus put to the left of b)
*/

void	btree_insert(t_btree **btree, void *data, int (*cmp)(void *, void *))
{
	if (*btree == NULL)
		*btree = btree_new(data);
	else
	{
		if (cmp(data, (*btree)->data))
			btree_insert(&((*btree)->left), data, cmp);
		else
			btree_insert(&((*btree)->right), data, cmp);
	}
}
