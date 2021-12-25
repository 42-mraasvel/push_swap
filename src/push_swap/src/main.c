/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/07 11:10:49 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/09 23:37:57 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"
#include "libft.h"
#include <stdlib.h>

static int	end_program(t_data *data)
{
	stack_delete(data->a);
	stack_delete(data->b);
	free(data->sorted_ptrs);
	return (0);
}

static int	init_program(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	data->a = stack_init('a');
	data->b = stack_init('b');
	return (0);
}

static void	sort(t_data *data)
{
	if (stack_issorted(data->a))
		return ;
	if (data->a->size <= 5)
		smallsort(data);
	else
		bigsort(data);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc == 1)
		return (0);
	init_program(&data);
	data.total = parse_args(argc, argv, 0, &data.a);
	if (data.total == ERROR)
		return (end_program(&data));
	data.sorted_ptrs = set_indexes(data.a, data.total);
	sort(&data);
	end_program(&data);
	return (0);
}
