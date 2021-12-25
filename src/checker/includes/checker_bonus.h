/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_bonus.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 11:39:49 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/11 15:25:37 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# ifndef DELAY
#  define DELAY 500000
# endif

# include "checker.h"

typedef struct s_printing
{
	int		maxlen;
	char	*spaces;
	int		nspaces;
	t_dlist	*last[4];
	char	colors[2][10];
}	t_printing;

typedef int	(*t_flagfct)(int, char **, int *, t_data *);

t_flagfct	flag_func(int flag);

int			is_last_arg(int argc, int i);

/* Visualization */

# define CUR_TL "\033[;H"
# define ERASE_DISPLAY "\033[2J"
# define NSPACES 10

# define REDCLR "\033[1;32m"
# define EMPTYSTR ""
# define RESETCLR "\033[0m"

void		print_start(t_data *data, t_printing *info);
void		print_state(t_data *data, t_printing *info);
void		printspaces(t_printing *info);
void		clear_screen(void);

void		color_init(t_printing *info);
char		*getcolor(t_dlist *p, t_printing *info);
void		set_color_ptr(t_data *data, t_printing *info, int op);

int			execute_mlx(t_data *data);

#endif
