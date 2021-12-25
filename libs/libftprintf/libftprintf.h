/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 10:02:53 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 11:58:28 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdint.h>
# include <stddef.h>
# include <stdarg.h>

int					ft_printf(const char *format, ...);

/*
** Signs to signal which flags are on.
*/

typedef struct s_flags
{
	int		hash;
	int		zero;
	int		minus;
	int		space;
	int		plus;
	int		field_width;
	int		precision;
	int		l;
	int		ll;
	int		h;
	int		hh;
}					t_flags;

/*
** conversion.c
*/

int					conversion(const char *format,
						size_t *i, va_list start, int n);

/*
** flagsequence.c / flagsequence_utils.c
*/

int					ft_is_printf_flag(char c);
int					check_max_accepted_value(const char *number);
t_flags				flags_sequence_one(const char *format, size_t *i);
t_flags				flags_sequence_two(const char *format, size_t *i,
						t_flags flags, va_list start);
t_flags				flags_sequence_three(const char *format,
						size_t *i, t_flags flags);

/*
** convert_*.c functions
*/

int					convert_percentage(t_flags flags);
int					convert_character(va_list start, t_flags flags);
int					convert_string(va_list start, t_flags flags);
int					convert_pointer(va_list start, t_flags flags);
int					convert_digit(va_list start, t_flags flags);
int					convert_udigit(va_list start, t_flags flags);
int					convert_hex(va_list start, t_flags flags, int upcase);
int					convert_n(va_list start, t_flags flags, int n);
int					convert_f(va_list start, t_flags flags);
int					convert_e(va_list start, t_flags flags);

/*
** conversion_utils.c
*/

int					put_fw(int field_width, int zero);
unsigned long long	get_unsigned_nbr(va_list start, t_flags flags);

/*
** For double conversions
*/

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
