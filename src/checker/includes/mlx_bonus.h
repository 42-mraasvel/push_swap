/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_bonus.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/11 15:18:58 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/12 22:48:38 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_BONUS_H
# define MLX_BONUS_H

# include "checker_bonus.h"
# include <pthread.h>

# define WINX 1080
# define WINY 720

# define MIN_DELAY 0
# define MAX_DELAY 500000
# define DELAY_INC 75000

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_box
{
	t_point	botright;
	int		height;
	int		width;
}	t_box;

typedef union u_col
{
	unsigned int	col;
	struct
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
		unsigned char	t;
	};
}	t_col;

typedef struct s_line
{
	int		height;
	int		width;
	t_col	col;
	t_point	start;
}	t_line;

typedef struct s_scene
{
	t_line	*lines;
	t_box	a;
	t_box	b;
}	t_scene;

typedef struct s_rdata
{
	t_data		*data;
	int			changed;
	int			active;
	int			finished;
	pthread_t	ptid;
	int			quit_request;
	int			delay;
	t_scene		*scene;
	int			paused;
	int			next;
}	t_rdata;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		w;
	int		h;
}	t_img;

typedef struct s_wdata
{
	int	winx;
	int	winy;
}	t_wdata;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*img1;
	t_img	*img2;
	t_wdata	wdata;
	t_rdata	rdata;
}	t_mlx;

int		init_viz(t_mlx *mlx);
int		end_mlx(t_mlx *mlx, int status);
void	activate_hooks(t_mlx *mlx);
int		render_frame(t_mlx *mlx, t_img *img);
int		execute_operations(t_mlx *mlx);

void	ft_pixelput(t_img *img, int x, int y, t_col color);
t_col	col_gen(int r, int g, int b);
t_col	gradient_rb(float percent);

void	scene_destroy(t_scene *scene);
t_scene	*scene_init(t_mlx *mlx);
t_line	*getlines(t_mlx *mlx, t_scene *scene);

void	draw_box(t_img *img, t_box box);
void	draw_line(t_img *img, t_line line);
void	draw_stack(t_img *img, t_stack *s, t_box b, t_scene *scene);

#endif
