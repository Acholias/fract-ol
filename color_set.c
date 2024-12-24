/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:38:58 by lumugot           #+#    #+#             */
/*   Updated: 2024/12/24 14:12:53 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	inter_color(int color1, int color2, double ratio)
{
	int	r;
	int	g;
	int	b;

	r = ((color1 >> 16) & 0xFF) * (1 - ratio) + ((color2 >> 16) & 0xFF) * ratio;
	g = ((color1 >> 8) & 0xFF) * (1 - ratio) + ((color2 >> 8) & 0xFF) * ratio;
	b = (color1 & 0xFF) * (1 - ratio) + (color2 & 0xFF) * ratio;
	return ((r << 16) | (g << 8) | b);
}

int	get_color(int iter, int max_iter, t_fractol *fractol)
{
	double	ratio;
	int		start_color;
	int		end_color;

	if (iter == fractol->max_iter)
		return (BLACK);
	ratio = (double)iter / max_iter;
	if (fractol->current_color == 1)
	{
		start_color = PALETTE_1_START;
		end_color = PALETTE_1_END;
	}
	else if (fractol->current_color == 2)
	{
		start_color = PALETTE_2_START;
		end_color = PALETTE_2_END;
	}
	else if (fractol->current_color == 3)
	{
		start_color = PALETTE_3_START;
		end_color = PALETTE_3_END;
	}
	else
		get_color(iter, max_iter, fractol);
	return (inter_color(start_color, end_color, ratio));
}
