/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:00:44 by lumugot           #+#    #+#             */
/*   Updated: 2025/04/11 01:52:04 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# include <libft.h>
# include "../minilibx-linux/mlx.h"

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 70

# define SPACE 32
# define F1 65470
# define F2 65471
# define ESC 65307
# define SHIFT_L 65505

# define INCREASE_RENDER 65365
# define DECREASE_RENDER 65366

# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define ARROW_UP 65362
# define ARROW_DOWN 65364

# define PALETTE_MAX 9

typedef int	(*t_palette_func)(int, int);

typedef struct s_fractol
{
	void	*mlx;
	void	*mlx_win;
	int		*img;
	char	*addr;
	int		bits_pixel;
	int		line_lenght;
	int		endian;
	int		width;
	int		height;
	int		iter;
	int		max_iter;
	int		current_color;
	int		type;
	int		follow_mouse;
	int		flow;
	int		animate;
	double	julia_r;
	double	julia_i;
	double	min_i;
	double	max_i;
	double	min_r;
	double	max_r;
}	t_fractol;

typedef struct s_complex
{
	double	i;
	double	r;
}	t_complex;

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}	t_color;

//color_set.c
int		palette_forest(int iter, int max_iter);
int		palette_ocean(int iter, int max_iter);
int		palette_autumn(int iter, int max_iter);
int		palette_nebula(int iter, int max_iter);
int		get_color(int iter, int max_iter, t_fractol *data);

//color_set_bis.c
int		palette_galaxy(int iter, int max_iter);
int		palette_tropical(int iter, int max_iter);
int		palette_inferno(int iter, int max_iter);
int		palette_aurora_borealis(int iter, int max_iter);
int		palette_sunset(int iter, int max_iter);

//mandelbrot.c
int		set_mandelbrot(t_complex z, t_fractol *fractol);
void	draw_mandelbrot(t_fractol *fractol);

//julia.c
int		julia_moove(t_fractol *f);
int		set_julia(t_complex z, t_complex c, t_fractol *fractol);
void	draw_julia(t_fractol *fractol);

//burningship.c
double	my_abs(double a);
int		set_burningship(t_complex z, t_fractol *fractol);
void	draw_burningship(t_fractol *data);

//choice_fractal.c
void	print_helper(void);
int		select_fractal(t_fractol *fractol, int argc, char **argv);
int		print_fractal(t_fractol *fractol);

//fractol_tools.c
int		destroy_fractal(t_fractol *fractol);
int		handle_mouse(int button, int x, int y, t_fractol *fractol);
void	zoom(int x, int y, t_fractol *fractol, double zoom_factor);

//hook.c
int		mouse_moove_julia(int x, int y, t_fractol *data);
void	move_view_in_direction(t_fractol *pos, double m_r, double m_i, int k);
void	moove_view(int keycode, t_fractol *fractol);
int		handle_view_and_color_change(int keycode, t_fractol *fractol);
int		handle_iteration_change(int keycode, t_fractol *fractol);

//setup_window.c
void	init_fractal(t_fractol *fractol);
int		handle_input(int keycode, t_fractol *fractol);
void	put_pixel(t_fractol *data, int x, int y, int color);
int		init_window(t_fractol *fractol);

#endif
