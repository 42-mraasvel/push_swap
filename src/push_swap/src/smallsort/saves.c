/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   saves.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/09 22:33:17 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 14:30:13 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "smallsort.h"

t_saves	*saves_init(void)
{
	t_saves	*saves;

	saves = ft_malloc(1 * sizeof(t_saves));
	saves->size = HASH_SIZE;
	saves->table = (t_list **)ft_malloc(HASH_SIZE * sizeof(t_list *));
	ft_bzero(saves->table, HASH_SIZE * sizeof(t_list *));
	return (saves);
}

void	saves_delete(t_saves *saves, void (*del)(void *))
{
	int	i;

	i = 0;
	while (i < saves->size)
	{
		if (saves->table[i])
			ft_lstclear(&(saves->table[i]), del);
		i++;
	}
	free(saves->table);
	free(saves);
}

static unsigned int	hash(t_state *key)
{
	unsigned int	indexa;
	unsigned int	indexb;
	unsigned int	i;

	indexa = 1;
	indexb = 1;
	i = 0;
	while (i < (unsigned int)key->total)
	{
		if (i < (unsigned int)key->size_a)
			indexa *= (key->table[i] * 0x12F39847) ^ (i * i);
		else
			indexb *= (key->table[i] * 0x12F39847) ^ (i * i);
		i++;
	}
	return (indexa + indexb);
}

static int	key_exists(t_saves *saves, t_state *key, int index)
{
	t_list	*cur;

	cur = saves->table[index];
	while (cur)
	{
		if (state_cmp(key, cur->content))
			return (true);
		cur = cur->next;
	}
	return (false);
}

/*
** Return true if added successfully
** False if save already existed
*/

int	saves_add(t_saves *saves, void *key)
{
	unsigned int	index;
	t_list			*new;

	index = hash(key) % saves->size;
	if (key_exists(saves, key, index))
		return (false);
	new = oom_guard(ft_lstnew(key));
	ft_lstadd_front(&(saves->table[index]), new);
	return (true);
}
