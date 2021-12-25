/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/10 08:06:57 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 20:16:37 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "libft.h"
#include "libps.h"
#include "checker.h"

static void	init_program(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	data->a = stack_init('a');
	data->b = stack_init('b');
	data->ops = ops_init(0);
	data->bonus = ft_malloc(1 * sizeof(t_bonus));
	ft_bzero(data->bonus, sizeof(t_bonus));
}

static int	end_program(t_data *data)
{
	stack_delete(data->a);
	stack_delete(data->b);
	if (data->ops)
		ops_delete(data->ops);
	free(data->bonus);
	return (OK);
}

static int	check_sorted(t_data *data)
{
	if (stack_isempty(data->b) && stack_issorted(data->a))
		return (true);
	return (false);
}

static void	set_sorted(t_data *data)
{
	t_dlist	**sorted_ptrs;

	sorted_ptrs = set_indexes(data->a, data->total);
	free(sorted_ptrs);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc == 1)
		return (0);
	init_program(&data);
	if (args(&data, argc, argv) != OK)
		return (end_program(&data));
	set_sorted(&data);
	if (get_ops(&data) == ERROR)
		return (end_program(&data));
	if (execute(&data) == ERROR)
		return (end_program(&data));
	if (check_sorted(&data))
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	end_program(&data);
	return (0);
}
