/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 22:55:11 by lumugot           #+#    #+#             */
/*   Updated: 2024/12/23 18:23:15 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int destroy_fractal(t_fractol *fractol)
{
    mlx_clear_window(fractol->mlx, fractol->mlx_win);
    mlx_destroy_image(fractol->mlx, fractol->img);
    mlx_destroy_window(fractol->mlx, fractol->mlx_win);
    mlx_destroy_display(fractol->mlx);
    mlx_loop_end(fractol->mlx);
    free(fractol->mlx);
    free(fractol);
    exit (0);
}

int handle_mouse(int button, int x, int y, t_fractol *fractol)
{
    if (button == 4)
        zoom(x, y, fractol, 0.9);
    else if (button == 5)
        zoom(x, y, fractol, 1.1);
    return (0);
}

void zoom(int x, int y, t_fractol *fractol, double zoom_factor)
{
    double mouse_real;
    double mouse_imag;
    double width;
    double height;

    width = fractol->max_real - fractol->min_real;  //calcul en fonction des bornes de la fenetre (largeur)
    height = fractol->max_image - fractol->min_image;  //calcul en fonction des bornes de la fenetre (longueur)
    mouse_real = fractol->min_real + (double)x / fractol->width * width;  // coordonnes de la souris (x)
    mouse_imag = fractol->min_image + (double)y / fractol->height * height; // coordonnes de la souris (y)
    fractol->min_real = mouse_real - (mouse_real - fractol->min_real) * zoom_factor;
    fractol->max_real = mouse_real + (fractol->max_real - mouse_real) * zoom_factor;
    fractol->min_image = mouse_imag - (mouse_imag - fractol->min_image) * zoom_factor;
    fractol->max_image = mouse_imag + (fractol->max_image - mouse_imag) * zoom_factor;
    draw_mandelbrot(fractol);
    mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, fractol->img, 0, 0);
}

