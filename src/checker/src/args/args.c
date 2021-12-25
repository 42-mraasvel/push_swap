/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   args.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/10 09:17:10 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 20:16:25 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	args(t_data *data, int argc, char *argv[])
{
	data->total = parse_args(argc, argv, 0, &data->a);
	if (data->total == ERROR)
		return (ERROR);
	return (OK);
}
