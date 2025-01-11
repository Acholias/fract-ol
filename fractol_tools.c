/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 22:55:11 by lumugot           #+#    #+#             */
/*   Updated: 2025/01/08 20:07:01 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	destroy_fractal(t_fractol *fractol)
{
	mlx_clear_window(fractol->mlx, fractol->mlx_win);
	mlx_destroy_image(fractol->mlx, fractol->img);
	mlx_destroy_window(fractol->mlx, fractol->mlx_win);
	mlx_destroy_display(fractol->mlx);
	mlx_loop_end(fractol->mlx);
	free(fractol->mlx);
	free(fractol);
	exit(0);
}

int	handle_mouse(int button, int x, int y, t_fractol *fractol)
{
	if (button == 4)
		zoom(x, y, fractol, 0.9);
	else if (button == 5)
		zoom(x, y, fractol, 1.1);
	return (0);
}

void	zoom(int x, int y, t_fractol *fractol, double zoom_f)
{
	double	mouse_r;
	double	mouse_i;
	double	width;
	double	height;

	width = fractol->max_r - fractol->min_r;
	height = fractol->max_i - fractol->min_i;
	mouse_r = fractol->min_r + (double)x / fractol->width * width;
	mouse_i = fractol->min_i + (double)y / fractol->height * height;
	fractol->min_r = mouse_r - (mouse_r - fractol->min_r) * zoom_f;
	fractol->max_r = mouse_r + (fractol->max_r - mouse_r) * zoom_f;
	fractol->min_i = mouse_i - (mouse_i - fractol->min_i) * zoom_f;
	fractol->max_i = mouse_i + (fractol->max_i - mouse_i) * zoom_f;
	mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, fractol->img, 0, 0);
}
