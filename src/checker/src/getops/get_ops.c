/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_ops.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/11 14:01:19 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 17:07:54 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "checker.h"

int	get_ops(t_data *data)
{
	return (parse_ops(data->ops, STDIN_FILENO));
}
