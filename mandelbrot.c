/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:42:38 by lumugot           #+#    #+#             */
/*   Updated: 2025/01/06 17:22:14 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	set_mandelbrot(t_complex z, t_fractol *fractol)
{
	int			iter;
	t_complex	c;
	t_complex	temp;

	c = z;
	iter = 0;
	while (iter < fractol->max_iter)
	{
		if ((z.r * z.r + z.i * z.i) > 4)
			break ;
		temp.r = z.r * z.r - z.i * z.i + c.r;
		temp.i = 2 * z.r * z.i + c.i;
		z.r = temp.r;
		z.i = temp.i;
		iter++;
	}
	return (iter);
}

void	draw_mandelbrot(t_fractol *data)
{
	int			x;
	int			y;
	int			color;
	t_complex	z;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			z.r = data->min_r + x * (data->max_r - data->min_r) / data->width;
			z.i = data->min_i + y * (data->max_i - data->min_i) / data->height;
			data->iter = set_mandelbrot(z, data);
			color = get_color(data->iter, data->max_iter, data);
			put_pixel(data, x, y, color);
			x++;
		}
		y++;
	}
}
