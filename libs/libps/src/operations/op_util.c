/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_util.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/10 10:46:39 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/10 10:48:30 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ft_swapint(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_swapentry(t_dlist *a, t_dlist *b)
{
	ft_swapint(&a->data, &b->data);
	ft_swapint(&a->rvalue, &b->rvalue);
	ft_swapint(&a->segment, &b->segment);
}
