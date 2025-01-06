/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:21:05 by lumugot           #+#    #+#             */
/*   Updated: 2025/01/06 21:10:33 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	palette_forest(int iter, int max_iter)
{
	double	t;
	t_color	rgb;

	ft_memset(&rgb, 0, sizeof(rgb));
	t = (double)iter / (double)max_iter;
	if (t < 0.2)
		rgb = (t_color){0, 255 * (t / 0.2), 0};
	else if (t < 0.4)
		rgb = (t_color){0, 255, 255 * ((t - 0.2) / 0.2)};
	else if (t < 0.6)
		rgb = (t_color){255 * ((t - 0.4) / 0.2), 255, 0};
	else if (t < 0.8)
		rgb = (t_color){255, 255 * ((t - 0.6) / 0.2), 0};
	return (((int)rgb.r << 16) | ((int)rgb.g << 8) | (int)rgb.b);
}

int	palette_ocean(int iter, int max_iter)
{
	double	t;
	t_color	rgb;

	ft_memset(&rgb, 0, sizeof(rgb));
	t = (double)iter / (double)max_iter;
	if (t < 0.2)
		rgb = (t_color){0, 0, 255 * (t / 0.2)};
	else if (t < 0.4)
		rgb = (t_color){0, 0, 255 - 255 * ((t - 0.2) / 0.2)};
	else if (t < 0.6)
		rgb = (t_color){255 * ((t - 0.4) / 0.2), 0, 255};
	else if (t < 0.8)
		rgb = (t_color){255 - 255 * ((t - 0.6) / 0.2), 0, 255};
	return (((int)rgb.r << 16) | ((int)rgb.g << 8) | (int)rgb.b);
}

int	palette_autumn(int iter, int max_iter)
{
	double	t;
	t_color	rgb;

	ft_memset(&rgb, 0, sizeof(rgb));
	t = (double)iter / (double)max_iter;
	if (t < 0.2)
		rgb = (t_color){255, 255 * (t / 0.2), 0};
	else if (t < 0.4)
		rgb = (t_color){255 - 255 * ((t - 0.2) / 0.2), 255, 0};
	else if (t < 0.6)
		rgb = (t_color){255, 255 - 255 * ((t - 0.4) / 0.2), 0};
	else if (t < 0.8)
		rgb = (t_color){255, 0, 0};
	return (((int)rgb.r << 16) | ((int)rgb.g << 8) | (int)rgb.b);
}

int	palette_nebula(int iter, int max_iter)
{
	double	t;
	t_color	rgb;

	ft_memset(&rgb, 0, sizeof(rgb));
	t = (double)iter / (double)max_iter;
	if (t < 0.2)
		rgb = (t_color){0 + 255 * (t / 0.2), 0, 255 - 255 * (t / 0.2)};
	else if (t < 0.4)
		rgb = (t_color){255, 0, 255 - 255 * ((t - 0.2) / 0.2)};
	else if (t < 0.6)
		rgb = (t_color){255 - 255 * ((t - 0.4) / 0.2), 0, 255};
	else if (t < 0.8)
		rgb = (t_color){255, 255 - 255 * ((t - 0.6) / 0.2), 255};
	return (((int)rgb.r << 16) | ((int)rgb.g << 8) | (int)rgb.b);
}

int	get_color(int iter, int max_iter, t_fractol *data)
{
	if (iter == max_iter)
		return (0x000000);
	if (data->current_color == 1)
		return (palette_galaxy(iter, max_iter));
	else if (data->current_color == 2)
		return (palette_tropical(iter, max_iter));
	else if (data->current_color == 3)
		return (palette_inferno(iter, max_iter));
	else if (data->current_color == 4)
		return (palette_aurora_borealis(iter, max_iter));
	else if (data->current_color == 5)
		return (palette_sunset(iter, max_iter));
	else if (data->current_color == 6)
		return (palette_forest(iter, max_iter));
	else if (data->current_color == 7)
		return (palette_ocean(iter, max_iter));
	else if (data->current_color == 8)
		return (palette_autumn(iter, max_iter));
	else if (data->current_color == 9)
		return (palette_nebula(iter, max_iter));
	get_color(iter, max_iter, data);
	return (0);
}
