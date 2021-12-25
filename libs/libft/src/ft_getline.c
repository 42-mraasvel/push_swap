/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_getline.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/10 09:00:28 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/13 11:50:15 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_getline.h"

static void	*gnl_memcpy(void *dest, void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	i = 0;
	d = dest;
	s = src;
	if (dest == src)
		return (dest);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

static int	scan_buffer(t_buffer *buffer, t_ret *ret)
{
	int	i;
	int	bytes_read;

	i = buffer->position;
	while (buffer->buffer[i] != '\0' && buffer->buffer[i] != '\n')
		i++;
	bytes_read = i - buffer->position;
	if (buffer->buffer[i] == '\0' || buffer->buffer[i + 1] == '\0')
		buffer->position = 0;
	else
		buffer->position = i + 1;
	if (buffer->buffer[i] == '\n')
		*ret = line_read;
	else
		*ret = cont_read;
	return (bytes_read);
}

/*
** return: 1 for newline found.
** return: 0 for continue reading.
** return: -1 for error (malloc)
** Stores buffer up to newline or '\0' in line.
** Updates line_size and position.
*/

static int	clear_buffer(t_buffer *buffer, char **line, int *line_size)
{
	char	*new_line;
	t_ret	ret;
	int		new_size;
	int		pos;

	pos = buffer->position;
	new_size = scan_buffer(buffer, &ret);
	new_line = (char *)malloc((new_size + *line_size + 1) * sizeof(char));
	if (new_line == NULL)
		return (error);
	gnl_memcpy(new_line, *line, *line_size);
	gnl_memcpy(new_line + *line_size, buffer->buffer + pos, new_size);
	if (*line_size != 0)
		free(*line);
	*line = new_line;
	*line_size += new_size;
	(*line)[*line_size] = '\0';
	return (ret);
}

static int	fill_buffer(int fd, char **line, t_buffer *buffer, int *line_size)
{
	ssize_t	read_ret;
	t_ret	clear_ret;

	while (1)
	{
		read_ret = read(fd, buffer->buffer, BUFFER_SIZE);
		if (read_ret == -1)
			return (error);
		buffer->buffer[read_ret] = '\0';
		clear_ret = clear_buffer(buffer, line, line_size);
		if (clear_ret == error)
			return (error);
		if (read_ret == eof_read)
			return (eof_read);
		if (clear_ret == line_read)
			return (line_read);
	}
	return (0);
}

/*
** return: 1 for line read.
** return: 0 for EOF read.
** return: -1 for error (read or malloc).
** An enum is used to determine return values
*/

int	ft_getline(int fd, char **line)
{
	static t_buffer	buffer;
	t_ret			ret;
	int				line_size;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (error);
	line_size = 0;
	if (buffer.position != 0)
	{
		ret = clear_buffer(&buffer, line, &line_size);
		if (ret == error && line_size != 0)
			free(*line);
		if (ret == error)
			return (error);
		if (ret == line_read)
			return (line_read);
	}
	ret = fill_buffer(fd, line, &buffer, &line_size);
	if (ret == error && line_size != 0)
		free(*line);
	return (ret);
}
