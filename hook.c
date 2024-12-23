/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:24:12 by lumugot           #+#    #+#             */
/*   Updated: 2024/12/23 19:44:49 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int key_hook(int keycode, t_fractol *fractol)
{
    if (keycode == SPACE)
	{
        fractol->current_color++;
        if (fractol->current_color > 3)
            fractol->current_color = 1;
    }
    return (0);
}

void move_view_in_direction(t_fractol *fractol, double move_real, double move_image, int keycode)
{
    if (keycode == ARROW_LEFT)
    {
        fractol->min_real -= move_real;
        fractol->max_real -= move_real;
    }
    else if (keycode == ARROW_RIGHT)
    {
        fractol->min_real += move_real;
        fractol->max_real += move_real;
    }
    else if (keycode == ARROW_UP)
    {
        fractol->min_image -= move_image;
        fractol->max_image -= move_image;
    }
    else if (keycode == ARROW_DOWN)
    {
        fractol->min_image += move_image;
        fractol->max_image += move_image;
    }
}

void moove_view(int keycode, t_fractol *fractol)
{
    double move_real = (fractol->max_real - fractol->min_real) * 0.05;
    double move_image = (fractol->max_image - fractol->min_image) * 0.05;

    move_view_in_direction(fractol, move_real, move_image, keycode);
    draw_mandelbrot(fractol);
    mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, fractol->img, 0, 0);
}


int handle_view_and_color_change(int keycode, t_fractol *fractol)
{
    if (keycode == SPACE)
    {
        fractol->current_color++;
        if (fractol->current_color > 3)
            fractol->current_color = 1;
        draw_mandelbrot(fractol);
        mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, fractol->img, 0, 0);
    }
    if (keycode == ARROW_LEFT || keycode == ARROW_RIGHT || keycode == ARROW_UP || keycode == ARROW_DOWN)
        moove_view(keycode, fractol);

    return 0;
}

int handle_iteration_change(int keycode, t_fractol *fractol)
{
    if (keycode == 65365)
    {
        if (fractol->max_iter < 500)
            fractol->max_iter += 10;
    }
    else if (keycode == 65366)
    {
        if (fractol->max_iter > 10)
            fractol->max_iter -= 10;
    }
    return 0;
}




