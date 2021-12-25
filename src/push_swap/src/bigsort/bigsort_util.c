/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bigsort_util.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/08 21:46:36 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/08 21:47:45 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int	ft_isseg(int a, t_segment *seg)
{
	return (a >= seg->min && a <= seg->max);
}
