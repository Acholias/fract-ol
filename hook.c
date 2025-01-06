/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:24:12 by lumugot           #+#    #+#             */
/*   Updated: 2025/01/06 21:00:22 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	print_fractal(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, fractol->img, 0, 0);
}

int	handle_view_and_color_change(int k, t_fractol *data)
{
	if (k == SPACE)
	{
		data->current_color++;
		if (data->current_color > 9)
			data->current_color = 1;
		print_fractal(data);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	}
	if (k == ARROW_LEFT || k == ARROW_RIGHT || k == ARROW_UP || k == ARROW_DOWN)
		moove_view(k, data);
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
