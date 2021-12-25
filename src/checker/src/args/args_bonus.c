/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   args_bonus.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/10 09:18:10 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/14 08:10:48 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"
#include "checker_bonus.h"

int	is_last_arg(int argc, int i)
{
	if (i == argc - 1)
		return (true);
	return (false);
}

static int	check_flag(char *str)
{
	static const char	*flags[] = {
		[v_flag] = "-v",
		[c_flag] = "-c",
		[f_flag] = "-f",
		NULL
	};
	int					i;

	i = 0;
	while (flags[i])
	{
		if (ft_strcmp(flags[i], str) == 0)
			return (i);
		i++;
	}
	return (ERROR);
}

static int	parse_flags(int argc, char *argv[], t_data *data)
{
	int	i;
	int	flag;

	i = 1;
	while (i < argc && argv[i][0] == '-')
	{
		if (ft_isdigit(argv[i][1]))
			break ;
		flag = check_flag(argv[i]);
		if (flag == ERROR)
			return (ft_error("Invalid flag: ", argv[i]));
		if (flag_func(flag)(argc, argv, &i, data) == ERROR)
			return (ft_error("Flag parsing error: ", argv[i]));
		i ++;
	}
	return (i);
}

/* Flag parsing */
int	args(t_data *data, int argc, char *argv[])
{
	int	i;

	if (argc == 1)
		return (NOTHING);
	i = parse_flags(argc, argv, data);
	if (i == ERROR)
		return (ERROR);
	if (i == argc)
		return (NOTHING);
	data->total = parse_args(argc, argv, i, &data->a);
	if (data->total == ERROR)
		return (ERROR);
	return (OK);
}
