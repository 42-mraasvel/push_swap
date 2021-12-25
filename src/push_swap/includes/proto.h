#ifndef PROTO_H
# define PROTO_H

# include "struct.h"
# include "smallsort.h"
# include "libft.h"

/* Sorting algorithms */

int			smallsort(t_data *data);

/* Bigsort */

int			bigsort(t_data *data);

void		segment_insert(t_segment *new, t_list **list);
void		segment_split(int seg, t_list *segments, t_data *data);
void		segment_minsort(t_data *data, t_segment *seg);

int			ft_isseg(int a, t_segment *seg);
t_segment	*segment_new(int id, int min, int max);
t_stack		*segments_stack(t_data *data, int segment);
void		segment_rotate_top(t_stack *s, int segment, t_data *data);
t_stack		*other_stack(t_stack *s, t_data *data);

#endif
