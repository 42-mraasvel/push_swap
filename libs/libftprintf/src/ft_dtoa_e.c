/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dtoa_e.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 15:12:35 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 12:08:11 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_double.h"

static double	extract_n_significant_digits(double num, char *digits, int n)
{
	double	ten;
	int		c;

	ten = ft_pow(10, ft_dbl_tenthpow(num));
	while (n > 0)
	{
		c = (int)(num / ten);
		num = num - ten * (double)c;
		ten /= 10;
		if (c < 0)
			c = -c;
		if (c > 9)
			c = 1;
		*digits = c + '0';
		digits++;
		n--;
	}
	return (num);
}

static char	*create_exponent(int e)
{
	char	*exponent;
	char	*part_two;
	int		len;

	len = ft_numlen_base(e, 10);
	if (len == 1)
		len = 2;
	exponent = (char *)ft_calloc((len + 3), sizeof(char));
	if (exponent == NULL)
		return (NULL);
	if (e < 0)
		exponent[1] = '-';
	else
		exponent[1] = '+';
	exponent[0] = 'e';
	if (e < 0)
		e = -e;
	part_two = ft_llutoa(e, 2);
	if (part_two == NULL)
		return (NULL);
	ft_strlcat(exponent, part_two, len + 3);
	free(part_two);
	return (exponent);
}

static char	*create_e_string(char *digits, int e)
{
	char	*result;
	char	*exponent;
	int		len;

	len = ft_numlen_base(e, 10);
	if (len == 1)
		len = 2;
	len += ft_strlen(digits) + 3;
	result = (char *)ft_calloc((len + 1), sizeof(char));
	if (result == NULL)
		return (NULL);
	result[0] = digits[0];
	result[1] = '.';
	ft_strlcat(result, digits + 1, len + 1);
	exponent = create_exponent(e);
	if (exponent == NULL)
	{
		free(result);
		return (NULL);
	}
	ft_strlcat(result, exponent, len + 1);
	free(exponent);
	free(digits);
	return (result);
}

/*
** Return string in the format of:
** 1.2345+e12, scientific notation
** If precision = 0, the radix point will still be in the string.
** 1.e+0 for example.
*/

char	*ft_dtoa_e(double num, int precision)
{
	char	*digits;
	char	rounding_digits[16];
	int		e;

	digits = (char *)malloc((17 + precision) * sizeof(char));
	if (digits == NULL)
		return (NULL);
	digits[precision + 16] = '\0';
	e = ft_dbl_tenthpow(num);
	num = extract_n_significant_digits(num, digits, precision + 16);
	ft_strlcpy(rounding_digits, digits + precision + 1, 16);
	digits[precision + 1] = '\0';
	digits = ft_round_f(digits, rounding_digits);
	if (digits == NULL)
		return (NULL);
	if ((int)ft_strlen(digits) != precision + 1)
	{
		digits[precision + 1] = '\0';
		e++;
	}
	digits = create_e_string(digits, e);
	return (digits);
}
