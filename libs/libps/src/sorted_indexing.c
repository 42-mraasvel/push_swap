/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorted_indexing.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/07 14:42:14 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 20:12:26 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libps.h"

static int	compare_data(void *a, void *b)
{
	if (((t_dlist *)(a))->rvalue < ((t_dlist *)(b))->rvalue)
		return (true);
	return (false);
}

/*
** Set indexes (starting with largest)
** Sorted insert into the sorted_ptrs table
*/

static void	fill_table(t_btree *tree, t_dlist **table, int *total)
{
	if (tree == NULL)
		return ;
	fill_table(tree->right, table, total);
	table[*total] = (t_dlist *)(tree->data);
	((t_dlist *)(tree->data))->data = *total;
	*total -= 1;
	fill_table(tree->left, table, total);
}

/*
** Sorted insert into a binary tree each node
** so that we can set the indexes
** and return an array of the entries in sorted order
** Free table on return
*/

t_dlist	**set_indexes(t_stack *s, int total)
{
	t_btree	*tree;
	t_dlist	*cur;
	t_dlist	**table;

	tree = NULL;
	table = (t_dlist **)ft_malloc(total * sizeof(t_dlist *));
	cur = s->top;
	while (cur)
	{
		btree_insert(&tree, cur, compare_data);
		cur = cur->next;
	}
	total -= 1;
	fill_table(tree, table, &total);
	btree_delete(tree, NULL);
	return (table);
}
