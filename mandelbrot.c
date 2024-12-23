/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:42:38 by lumugot           #+#    #+#             */
/*   Updated: 2024/12/23 18:47:19 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int set_mandelbrot(t_complex z, t_fractol *fractol)
{
    int         iter;
    t_complex   c;
    t_complex   temp;

    c = z;  // C'est une copie de la position du pixel
    iter = 0;
    while (iter < fractol->max_iter)  // Utilisation de max_iter
    {
        if ((z.real * z.real + z.image * z.image) > 4)  // Condition de divergence
            break;
        temp.real = z.real * z.real - z.image * z.image + c.real;
        temp.image = 2 * z.real * z.image + c.image;
        z.real = temp.real;
        z.image = temp.image;
        iter++;
    }
    return (iter);
}


void draw_mandelbrot(t_fractol *fractol)
{
    int         x, y, iter;
    t_complex   z;

    y = 0;
    while (y < fractol->height)
    {
        x = 0;
        while (x < fractol->width)
        {
            z.real = fractol->min_real + x * (fractol->max_real - fractol->min_real) / fractol->width;
            z.image = fractol->min_image + y * (fractol->max_image - fractol->min_image) / fractol->height;
            iter = set_mandelbrot(z, fractol);  // On passe maintenant fractol comme argument
            int color = get_color(iter, fractol->max_iter, fractol);  // Utilisation de max_iter ici aussi
            put_pixel(fractol, x, y, color);  // Affichage du pixel
            x++;
        }
        y++;
    }
}

