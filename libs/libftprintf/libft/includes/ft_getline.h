/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_getline.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/10 08:59:11 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/16 23:30:26 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETLINE_H
# define FT_GETLINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef enum e_ret
{
	error = -1,
	eof_read,
	line_read,
	cont_read
}	t_ret;

typedef struct s_buffer
{
	char	buffer[BUFFER_SIZE + 1];
	int		position;
}	t_buffer;

int				ft_getline(int fd, char **line);

#endif
