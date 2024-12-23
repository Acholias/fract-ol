/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 22:38:51 by lumugot           #+#    #+#             */
/*   Updated: 2024/12/23 19:05:54 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_fractal(t_fractol *fractol)
{
    fractol->width = WIDTH;
    fractol->height = HEIGHT;
    fractol->min_real = -2.0;
    fractol->max_real = 1.0;
    fractol->min_image = -1.5;
    fractol->max_image = 1.5;
    fractol->max_iter = MAX_ITER;
    fractol->current_color = 1;
    fractol->img = mlx_new_image(fractol->mlx, fractol->width, fractol->height);
    if (!fractol->img)
    {
        free(fractol->mlx);
        free(fractol);
        exit(EXIT_FAILURE);
    }
    fractol->addr = mlx_get_data_addr(fractol->img, &fractol->bits_pixel,
                    &fractol->line_lenght, &fractol->endian);
}

// int handle_input(int keycode, t_fractol *fractol)
// {
//     if (keycode == ESC) 
//     {
//         destroy_fractal(fractol);
//         exit(EXIT_SUCCESS);
//     }
//     if (keycode == SPACE)
//     {
//         fractol->current_color++;
//         if (fractol->current_color > 3)
//             fractol->current_color = 1;
//         draw_mandelbrot(fractol);
//         mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, fractol->img, 0, 0);
//     }
//     else if (keycode == ARROW_LEFT || keycode == ARROW_RIGHT || keycode == ARROW_UP 
//             || keycode == ARROW_DOWN)
//         moove_view(keycode, fractol);
//     return (0);
// }

int handle_input(int keycode, t_fractol *fractol)
{
    if (keycode == ESC) // Quitter avec ESC
    {
        destroy_fractal(fractol);
        exit(EXIT_SUCCESS);
    }
    handle_iteration_change(keycode, fractol);
    handle_view_and_color_change(keycode, fractol);
    draw_mandelbrot(fractol);
    mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, fractol->img, 0, 0);

    return 0;
}

int init_window(t_fractol *fractol)
{
    fractol->mlx = mlx_init();
    if (!fractol->mlx)
        exit(EXIT_FAILURE);

    fractol->mlx_win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "mandelbrot");
    if (!fractol->mlx_win)
    {
        free(fractol->mlx);
        return (EXIT_FAILURE);
    }
    init_fractal(fractol);
    draw_mandelbrot(fractol);
    mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, fractol->img, 0, 0);
    mlx_mouse_hook(fractol->mlx_win, handle_mouse, fractol);
    mlx_hook(fractol->mlx_win, 17, 1L << 2, destroy_fractal, fractol);
    //mlx_key_hook(fractol->mlx_win, handle_iteration_change, fractol);
    mlx_key_hook(fractol->mlx_win, handle_input, fractol);
    mlx_loop(fractol->mlx);
    return (EXIT_SUCCESS);
}

void    put_pixel(t_fractol *data, int x, int y, int color)
{
        char    *dst;

        dst = data->addr + (y * data->line_lenght + x * (data->bits_pixel / 8));
        *(unsigned int *)dst = color;
}

int main(void)
{
    t_fractol *fractol;

    fractol = malloc(sizeof(t_fractol));
    if (!fractol)
        return (EXIT_FAILURE);
    init_window(fractol);
    return (EXIT_SUCCESS);
}