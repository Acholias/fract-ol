/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 22:38:51 by lumugot           #+#    #+#             */
/*   Updated: 2025/04/11 01:20:32 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_fractal(t_fractol *fractol)
{
	fractol->width = WIDTH;
	fractol->height = HEIGHT;
	fractol->min_r = -2.0;
	fractol->max_r = 1.0;
	fractol->min_i = -1.5;
	fractol->max_i = 1.5;
	fractol->iter = 0;
	fractol->follow_mouse = 0;
	fractol->flow = 0;
	fractol->animate = 0;
	fractol->max_iter = MAX_ITER;
	fractol->current_color = 0;
	fractol->img = mlx_new_image(fractol->mlx, fractol->width, fractol->height);
	if (!fractol->img)
	{
		destroy_fractal(fractol);
		exit(EXIT_FAILURE);
	}
	fractol->addr = mlx_get_data_addr(fractol->img, &fractol->bits_pixel,
			&fractol->line_lenght, &fractol->endian);
}

int	handle_input(int keycode, t_fractol *fractol)
{
	if (keycode == ESC)
	{
		destroy_fractal(fractol);
		exit(EXIT_SUCCESS);
	}
	if (keycode == SHIFT_L)
		fractol->animate = !fractol->animate;
	handle_iteration_change(keycode, fractol);
	handle_view_and_color_change(keycode, fractol);
	print_fractal(fractol);
	return (0);
}

void	put_pixel(t_fractol *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_pixel / 8));
	*(unsigned int *)dst = color;
}

int	init_window(t_fractol *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit (EXIT_FAILURE);
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fract-ol");
	if (!data->mlx_win)
	{
		mlx_destroy_display(data->mlx);
		return (EXIT_FAILURE);
	}
	init_fractal(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	mlx_mouse_hook(data->mlx_win, handle_mouse, data);
	mlx_hook(data->mlx_win, 17, 1L << 2, destroy_fractal, data);
	mlx_key_hook(data->mlx_win, handle_input, data);
	mlx_loop_hook(data->mlx, print_fractal, data);
	mlx_loop(data->mlx);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	if (argc < 2)
	{
		print_helper();
		return (0);
	}
	fractol = malloc(sizeof(t_fractol));
	if (!fractol)
		return (EXIT_FAILURE);
	select_fractal(fractol, argc, argv);
	if (!select_fractal(fractol, argc, argv))
		return (EXIT_FAILURE);
	init_window(fractol);
	return (0);
}
