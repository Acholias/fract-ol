/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:44:44 by lumugot           #+#    #+#             */
/*   Updated: 2025/04/11 01:19:38 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double	my_abs(double a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	set_burningship(t_complex z, t_fractol *fractol)
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
		temp.i = 2 * my_abs(z.r * z.i) + c.i;
		z.r = temp.r;
		z.i = temp.i;
		iter++;
	}
	return (iter);
}

void	draw_burningship(t_fractol *data)
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
			data->iter = set_burningship(z, data);
			color = get_color(data->iter, data->max_iter, data);
			put_pixel(data, x, y, color);
			x++;
		}
		y++;
	}
}
