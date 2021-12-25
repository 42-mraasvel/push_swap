/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   extra_wrappers.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/06 20:40:50 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/11 14:07:16 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libps.h"
#include "libft.h"

int	ft_perror(char *str)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (str)
		perror(str);
	else
		perror("Error");
	return (ERROR);
}

int	ft_error(char *prefix, char *str)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (prefix != NULL)
		ft_putstr_fd(prefix, STDERR_FILENO);
	if (str != NULL)
		ft_putstr_fd(str, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	return (ERROR);
}

void	exit_perror(char *s)
{
	ft_perror(s);
	exit(EXIT_FAILURE);
}

void	*oom_guard(void *ret)
{
	if (ret == NULL)
		exit_perror("malloc");
	return (ret);
}

void	*ft_malloc(size_t size)
{
	return (oom_guard(malloc(size)));
}
