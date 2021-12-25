/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flags_mlx.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/10 09:38:31 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 17:19:11 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include "checker_bonus.h"

static int	parse_v(int argc, char *argv[], int *i, t_data *data)
{
	data->bonus->flags.v = true;
	(void)argc;
	(void)argv;
	(void)i;
	return (OK);
}

static int	parse_c(int argc, char *argv[], int *i, t_data *data)
{
	data->bonus->flags.c = true;
	(void)argc;
	(void)argv;
	(void)i;
	return (OK);
}

static int	parse_f(int argc, char *argv[], int *i, t_data *data)
{
	if (is_last_arg(argc, *i))
		return (ERROR);
	(*i) += 1;
	data->bonus->flags.f = true;
	data->bonus->file = argv[*i];
	return (OK);
}

static int	parse_mlx(int argc, char *argv[], int *i, t_data *data)
{
	data->bonus->flags.mlx = true;
	(void)argc;
	(void)argv;
	(void)i;
	return (OK);
}

t_flagfct	flag_func(int flag)
{
	static t_flagfct	flags[] = {
		[v_flag] = parse_v,
		[c_flag] = parse_c,
		[f_flag] = parse_f,
		[mlx_flag] = parse_mlx
	};

	return (flags[flag]);
}
