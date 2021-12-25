/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_ops_bonus.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/11 14:02:10 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/11 14:05:47 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "checker.h"

int	get_ops(t_data *data)
{
	int	fd;
	int	result;

	result = OK;
	if (!data->bonus->flags.f)
		return (parse_ops(data->ops, STDIN_FILENO));
	fd = open(data->bonus->file, O_RDONLY);
	if (fd == -1)
		return (ft_perror(data->bonus->file));
	result = parse_ops(data->ops, fd);
	close(fd);
	return (result);
}
