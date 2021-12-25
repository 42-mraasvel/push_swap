/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/10 10:25:58 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/11 09:40:20 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "checker_bonus.h"
#include "libftprintf.h"

void	clear_screen(void)
{
	ft_putstr_fd(ERASE_DISPLAY CUR_TL, STDOUT_FILENO);
}

static void	print_entry(t_dlist *a, t_dlist *b, t_printing *info)
{
	char	*cola;
	char	*colb;

	cola = getcolor(a, info);
	colb = getcolor(b, info);
	printspaces(info);
	if (!a)
		ft_printf("%*c | %s%*d%s\n",
			info->maxlen, ' ', colb, info->maxlen, b->rvalue, RESETCLR);
	else if (!b)
		ft_printf("%s%*d%s |\n", cola, info->maxlen, a->rvalue, RESETCLR);
	else
	{
		ft_printf("%s%*d%s | ", cola, info->maxlen, a->rvalue, RESETCLR);
		ft_printf("%s%*d%s\n", colb, info->maxlen, b->rvalue, RESETCLR);
	}
}

void	print_state(t_data *data, t_printing *info)
{
	t_dlist	*ap;
	t_dlist	*bp;

	printspaces(info);
	ft_printf("%*c | %*c\n", info->maxlen, 'a', info->maxlen, 'b');
	printspaces(info);
	ft_printf("%*c | %*c\n", info->maxlen, '-', info->maxlen, '-');
	ap = data->a->top;
	bp = data->b->top;
	while (ap || bp)
	{
		print_entry(ap, bp, info);
		if (ap)
			ap = ap->next;
		if (bp)
			bp = bp->next;
	}
}

static void	setspaces(t_printing *info)
{
	info->nspaces = NSPACES;
	info->spaces = ft_malloc((NSPACES) * sizeof(char));
	ft_memset(info->spaces, ' ', NSPACES);
}

void	print_start(t_data *data, t_printing *info)
{
	clear_screen();
	setspaces(info);
	ft_printf("   OP:\n");
	print_state(data, info);
	usleep(DELAY);
}
