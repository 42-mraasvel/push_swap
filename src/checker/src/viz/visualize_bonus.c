/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   visualize_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/10 10:19:51 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 17:17:20 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "checker_bonus.h"
#include "libftprintf.h"

void	printspaces(t_printing *info)
{
	write(STDOUT_FILENO, info->spaces, info->nspaces);
}

static void	visualize(t_data *data, t_printing *info, int op)
{
	clear_screen();
	if (op != -1)
	{
		ft_printf("   OP: %s\n", get_op_str(op));
	}
	print_state(data, info);
	ft_printf("\n");
	usleep(DELAY);
}

static int	max_num(t_stack *s)
{
	int		max;
	t_dlist	*cur;

	cur = s->top;
	max = cur->rvalue;
	while (cur)
	{
		if (cur->rvalue > max)
			max = cur->rvalue;
		cur = cur->next;
	}
	return (max);
}

int	execute(t_data *data)
{
	size_t		i;
	t_printing	info;

	i = 0;
	ft_bzero(&info, sizeof(t_printing));
	if (data->bonus->flags.c)
		color_init(&info);
	info.maxlen = ft_numlen_base(max_num(data->a), 10);
	if (data->bonus->flags.v)
		print_start(data, &info);
	while (i < data->ops->len)
	{
		if (data->bonus->flags.c)
			set_color_ptr(data, &info, data->ops->table[i]);
		do_op(data->a, data->b, data->ops->table[i], false);
		if (data->bonus->flags.v)
			visualize(data, &info, data->ops->table[i]);
		i++;
	}
	if (data->bonus->flags.v)
		free(info.spaces);
	return (OK);
}
