/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_set_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:58:31 by lumugot           #+#    #+#             */
/*   Updated: 2025/01/06 21:12:09 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	palette_galaxy(int iter, int max_iter)
{
	double	t;
	t_color	rgb;

	ft_memset(&rgb, 0, sizeof(rgb));
	t = (double)iter / (double)max_iter;
	if (t < 0.2)
		rgb = (t_color){75 * (t / 0.2), 0, 100 + 155 * (t / 0.2)};
	else if (t < 0.4)
		rgb = (t_color){75 + 180 * ((t - 0.2) / 0.2), 0, 255 - 100 * \
			((t - 0.2) / 0.2)};
	else if (t < 0.6)
		rgb = (t_color){255, 255 * ((t - 0.4) / 0.2), 155};
	else if (t < 0.8)
		rgb = (t_color){255 - 255 * ((t - 0.6) / 0.2), 255 - 255 * \
				((t - 0.6) / 0.2), 155 - 155 * ((t - 0.6) / 0.2)};
	return (((int)rgb.r << 16) | ((int)rgb.g << 8) | (int)rgb.b);
}

int	palette_tropical(int iter, int max_iter)
{
	double	t;
	t_color	rgb;

	ft_memset(&rgb, 0, sizeof(rgb));
	t = (double)iter / (double)max_iter;
	if (t < 0.2)
		rgb = (t_color){0 + 255 * (t / 0.2), 255, 255 - 255 * (t / 0.2)};
	else if (t < 0.4)
		rgb = (t_color){255, 255 - 255 * ((t - 0.2) / 0.2), 0};
	else if (t < 0.6)
		rgb = (t_color){255 - 255 * ((t - 0.4) / 0.2), 255, 0};
	else if (t < 0.8)
		rgb = (t_color){0, 255 - 255 * ((t - 0.6) / 0.2), 0};
	return (((int)rgb.r << 16) | ((int)rgb.g << 8) | (int)rgb.b);
}

int	palette_inferno(int iter, int max_iter)
{
	double	t;
	t_color	rgb;

	ft_memset(&rgb, 0, sizeof(rgb));
	t = (double)iter / (double)max_iter;
	if (t < 0.2)
		rgb = (t_color){0 + 255 * (t / 0.2), 0, 0};
	else if (t < 0.4)
		rgb = (t_color){255, 255 * ((t - 0.2) / 0.2), 0};
	else if (t < 0.6)
		rgb = (t_color){255, 255 - 255 * ((t - 0.4) / 0.2), 0};
	else if (t < 0.8)
		rgb = (t_color){255, 0, 255 * ((t - 0.6) / 0.2)};
	return (((int)rgb.r << 16) | ((int)rgb.g << 8) | (int)rgb.b);
}

int	palette_aurora_borealis(int iter, int max_iter)
{
	double	t;
	t_color	rgb;

	ft_memset(&rgb, 0, sizeof(rgb));
	t = (double)iter / (double)max_iter;
	if (t < 0.2)
		rgb = (t_color){75 * (t / 0.2), 128 + 127 * (t / 0.2), 255 * \
			(t / 0.2)};
	else if (t < 0.4)
		rgb = (t_color){64 + 128 * ((t - 0.2) / 0.2), 255 - 255 * \
			((t - 0.2) / 0.2), 255};
	else if (t < 0.6)
		rgb = (t_color){192 - 192 * ((t - 0.4) / 0.2), 0, 255 - 255 * \
			((t - 0.4) / 0.2)};
	else if (t < 0.8)
		rgb = (t_color){255 * ((t - 0.6) / 0.2), 255 * \
			((t - 0.6) / 0.2), 0};
	return (((int)rgb.r << 16) | ((int)rgb.g << 8) | (int)rgb.b);
}

int	palette_sunset(int iter, int max_iter)
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
		rgb = (t_color){0, 255 - 255 * ((t - 0.4) / 0.2), 0};
	else if (t < 0.8)
		rgb = (t_color){255, 255 - 255 * ((t - 0.6) / 0.2), 0};
	return (((int)rgb.r << 16) | ((int)rgb.g << 8) | (int)rgb.b);
}
