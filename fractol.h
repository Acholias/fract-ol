/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:00:44 by lumugot           #+#    #+#             */
/*   Updated: 2025/01/06 21:13:32 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "Libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define WIDTH 1000
# define HEIGHT 1000
# define MAX_ITER 70

# define SPACE 32
# define ESC 65307

# define INCREASE_RENDER 65365
# define DECREASE_RENDER 65366

# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define ARROW_UP 65362
# define ARROW_DOWN 65364

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

int		palette_galaxy(int iter, int max_iter);
int		palette_tropical(int iter, int max_iter);
int		palette_inferno(int iter, int max_iter);
int		palette_aurora_borealis(int iter, int max_iter);
int		palette_sunset(int iter, int max_iter);
int		palette_forest(int iter, int max_iter);
int		palette_ocean(int iter, int max_iter);
int		palette_autumn(int iter, int max_iter);
int		palette_nebula(int iter, int max_iter);
int		select_fractal(t_fractol *fractol, int argc, char **argv);
void	print_fractal(t_fractol *fractol);
void	init_fractal(t_fractol *fractol);
int		handle_input(int keycode, t_fractol *fractol);
int		handle_view_and_color_change(int keycode, t_fractol *fractol);
int		init_window(t_fractol *fractol);
void	put_pixel(t_fractol *data, int x, int y, int color);
int		set_mandelbrot(t_complex z, t_fractol *fractol);
void	draw_mandelbrot(t_fractol *fractol);
int		set_julia(t_complex z, t_complex c, t_fractol *fractol);
void	draw_julia(t_fractol *fractol);
double	my_abs(double a);
int		set_burningship(t_complex z, t_fractol *fractol);
void	draw_burningship(t_fractol *data);
int		get_color(int iter, int max_iter, t_fractol *data);
int		handle_iteration_change(int keycode, t_fractol *fractol);
void	move_view_in_direction(t_fractol *pos, double m_r, double m_i, int k);
void	moove_view(int keycode, t_fractol *fractol);
int		destroy_fractal(t_fractol *fractol);
int		handle_mouse(int button, int x, int y, t_fractol *fractol);
void	zoom(int x, int y, t_fractol *fractol, double zoom_factor);

void	print_helper(void);

#endif