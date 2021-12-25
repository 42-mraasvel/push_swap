/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   smallsort.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/09 08:41:53 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 14:30:00 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SMALLSORT_H
# define SMALLSORT_H

# include "struct.h"
# include "libft.h"

typedef struct s_state
{
	char			size_a;
	char			total;
	char			*table;
	char			op;
	struct s_state	*prev;
}	t_state;

# define HASH_SIZE 10000

typedef struct s_saves
{
	t_list	**table;
	int		size;
}	t_saves;

typedef struct s_queue
{
	t_list	*start;
	t_list	*end;
}	t_queue;

void	state_delete(t_state *state);
void	state_delete_vp(void *state);
t_state	*original_state(t_data *data);
t_state	*state_new(t_state *prev, char size_a, char *table, char op);
int		state_cmp(t_state *a, t_state *b);

/* State operations / Expanding states */

t_state	*state_do_op(t_state *prev, char op);

typedef void	(*t_state_op)(t_state *, char *);

void	state_sa(t_state *state, char *new);
void	state_sb(t_state *state, char *new);
void	state_ss(t_state *state, char *new);
void	state_pa(t_state *state, char *new);
void	state_pb(t_state *state, char *new);
void	state_ra(t_state *state, char *new);
void	state_rb(t_state *state, char *new);
void	state_rr(t_state *state, char *new);
void	state_rra(t_state *state, char *new);
void	state_rrb(t_state *state, char *new);
void	state_rrr(t_state *state, char *new);

/* Queue : first in first out */

t_queue	*queue_init(void);
void	queue_delete(t_queue *queue, void (*del)(void *));
void	queue_add(t_queue *queue, void *data);
void	*queue_pop(t_queue *queue);
int		queue_empty(t_queue *queue);

/* Saves / hash table / set */

t_saves	*saves_init(void);
void	saves_delete(t_saves *saves, void (*del)(void *));
int		saves_add(t_saves *saves, void *key);

#endif
