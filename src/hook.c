/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:24:12 by lumugot           #+#    #+#             */
/*   Updated: 2025/04/11 01:20:27 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	mouse_moove_julia(int x, int y, t_fractol *f)
{
	if (x < 0 || x >= f->width || y < 0 || y >= f->height)
		return (0);
	f->julia_r = f->min_r + (double)x * (f->max_r - f->min_r) / f->width;
	f->julia_i = f->min_i + (double)y * (f->max_i - f->min_i) / f->height;
	mlx_clear_window(f->mlx, f->mlx_win);
	mlx_put_image_to_window(f->mlx, f->mlx_win, f->img, 0, 0);
	return (0);
}

void	move_view_in_direction(t_fractol *pos, double m_r, double m_i, int k)
{
	if (k == ARROW_LEFT)
	{
		pos->min_r -= m_r;
		pos->max_r -= m_r;
	}
	else if (k == ARROW_RIGHT)
	{
		pos->min_r += m_r;
		pos->max_r += m_r;
	}
	else if (k == ARROW_UP)
	{
		pos->min_i -= m_i;
		pos->max_i -= m_i;
	}
	else if (k == ARROW_DOWN)
	{
		pos->min_i += m_i;
		pos->max_i += m_i;
	}
}

void	moove_view(int kcode, t_fractol *fractol)
{
	double	m_r;
	double	m_i;

	m_r = (fractol->max_r - fractol->min_r) * 0.05;
	m_i = (fractol->max_i - fractol->min_i) * 0.05;
	move_view_in_direction(fractol, m_r, m_i, kcode);
	mlx_clear_window(fractol->mlx, fractol->mlx_win);
	print_fractal(fractol);
}

int	handle_view_and_color_change(int k, t_fractol *data)
{
	if (k == F2)
	{
		data->current_color = (data->current_color + 1) % PALETTE_MAX;
		mlx_clear_window(data->mlx, data->mlx_win);
	}
	else if (k == F1)
	{
		data->current_color = ((data->current_color - 1) + PALETTE_MAX) \
			% PALETTE_MAX;
		mlx_clear_window(data->mlx, data->mlx_win);
	}
	if (k == SPACE)
		data->follow_mouse = !data->follow_mouse;
	if (k == ARROW_LEFT || k == ARROW_RIGHT || k == ARROW_UP || k == ARROW_DOWN)
		moove_view(k, data);
	print_fractal(data);
	return (0);
}

int	handle_iteration_change(int kcode, t_fractol *fractol)
{
	if (kcode == INCREASE_RENDER)
	{
		if (fractol->max_iter < 500)
			fractol->max_iter += 10;
	}
	else if (kcode == DECREASE_RENDER)
	{
		if (fractol->max_iter > 10)
			fractol->max_iter -= 10;
	}
	return (0);
}
