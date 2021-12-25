/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_double.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 20:47:54 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 12:05:36 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOUBLE_H
# define FT_DOUBLE_H

# include <stdint.h>
# include "ft_conversion.h"

typedef union u_double
{
	double			value;
	struct			s_bitfield
	{
		uint64_t	mantissa : 52;
		uint16_t	exponent : 11;
		uint8_t		sign : 1;
	}				bits;
}					t_double;

char				*ft_dtoa_f(double nbr, int precision);
char				*ft_round_f(char *nbr, char *rounder);
char				*ft_dtoa_e(double num, int precision);
int					inf_nan(t_double nbr, t_flags flags);

#endif
