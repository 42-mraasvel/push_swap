#ifndef STRUCT_H
# define STRUCT_H

# include "libps.h"

typedef struct s_segment
{
	int	id;
	int	size;
	int	min;
	int	max;
	int	sorted;
}	t_segment;

typedef struct s_target
{
	int	bot_cur;
	int	bot_oth;
	int	top_oth;
}	t_target;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	t_dlist	**sorted_ptrs;
	int		total;
}	t_data;

#endif
