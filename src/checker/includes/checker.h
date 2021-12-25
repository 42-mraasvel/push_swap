/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 11:39:49 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/11 20:28:13 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libps.h"

# define NOTHING 1

typedef struct s_pwflags
{
	char	v;
	char	c;
	char	f;
	char	mlx;
}	t_pwflags;

enum e_flag
{
	v_flag,
	c_flag,
	f_flag,
	mlx_flag
};

typedef struct s_bonus
{
	t_pwflags	flags;
	char		*file;
}	t_bonus;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	t_ops	*ops;
	t_bonus	*bonus;
	int		total;
}	t_data;

int		args(t_data *data, int argc, char *argv[]);
int		execute(t_data *data);
int		get_ops(t_data *data);

#endif
