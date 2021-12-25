/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libps.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/06 20:24:02 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/10 10:48:38 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPS_H
# define LIBPS_H

# include <stddef.h>

# define ERROR -1
# define OK 0

typedef struct s_btree
{
	struct s_btree	*right;
	struct s_btree	*left;
	void			*data;
}	t_btree;

/*
** rvalue is the real int value
** data is the value in relation to other numbers
** as in: the smallest number always has data = 0
*/

typedef struct s_dlist
{
	int				data;
	int				rvalue;
	int				segment;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

typedef struct s_stack
{
	t_dlist	*top;
	t_dlist	*bot;
	size_t	size;
	char	type;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}	t_stacks;

/*
** All operations
*/

typedef enum e_optype
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}	t_optype;

typedef struct s_ops
{
	t_optype	*table;
	size_t		size;
	size_t		len;
}	t_ops;

/* Doubly Linked List Functions */

t_dlist		*dlist_create_elem(int data);
void		dlist_delete(t_dlist *start);
int			dlist_prepend(t_dlist **start, int data);
int			dlist_append(t_dlist **end, int data);

/* Stack Functions */

int			stack_push(t_stack *s, t_dlist *entry);
t_dlist		*stack_pop(t_stack *s);
int			stack_append_new(t_stack **s, int data);
void		stack_delete(t_stack *s);
t_stack		*stack_init(char type);

int			stack_isempty(t_stack *s);
int			stack_issorted(t_stack *s);

/* Wrappers / Utils */

void		*ft_malloc(size_t size);
void		exit_perror(char *s);
void		*oom_guard(void *ret);
int			ft_error(char *prefix, char *str);
int			ft_perror(char *str);

void		ft_swapentry(t_dlist *a, t_dlist *b);

/* Argument parsing */

int			parse_args(int argc, char *argv[], int start, t_stack **dst);
t_dlist		**set_indexes(t_stack *s, int total);

/* Operations */

typedef int	(*t_operation)(t_stack *, t_stack *);

int			do_op(t_stack *a, t_stack *b, t_optype op, int print);
t_optype	combined_op(t_optype op);
t_optype	invert_op(t_optype op);
char		*get_op_str(t_optype op);

/* Specific Versions */

int			ft_sa(t_stack *a, t_stack *b);
int			ft_sb(t_stack *a, t_stack *b);
int			ft_ss(t_stack *a, t_stack *b);
int			ft_pa(t_stack *a, t_stack *b);
int			ft_pb(t_stack *a, t_stack *b);
int			ft_ra(t_stack *a, t_stack *b);
int			ft_rb(t_stack *a, t_stack *b);
int			ft_rr(t_stack *a, t_stack *b);
int			ft_rra(t_stack *a, t_stack *b);
int			ft_rrb(t_stack *a, t_stack *b);
int			ft_rrr(t_stack *a, t_stack *b);

/* More Generic Versions */

int			ft_push(t_stack *dst, t_stack *src, int print);
int			ft_swap(t_stack *s, int print);
int			ft_rotate(t_stack *s, int print);
int			ft_rrotate(t_stack *s, int print);

/* Vector for operations */

t_optype	ops_get(t_ops *ops, size_t index);
int			ops_pushback(t_ops *ops, t_optype type);
int			ops_realloc(t_ops *ops);
void		ops_delete(t_ops *ops);
t_ops		*ops_init(size_t initial_size);

/* Parsing Operations from file or STDIN if NULL */

int			parse_ops(t_ops *ops, int fd);

/* Binary Tree */

t_btree		*btree_new(void *data);
void		btree_delete(t_btree *btree, void (*del)(void *));
void		btree_insert(t_btree **btree,
				void *data, int (*cmp)(void *, void *));

#endif
