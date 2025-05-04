/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:23:25 by lumugot           #+#    #+#             */
/*   Updated: 2025/04/11 01:59:56 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	print_helper(void)
{
	ft_putstr_fd("\033[38;5;34m  Arguments Inavlids !\033[00m\n", 2);
	ft_putstr_fd("\033[38;5;40m  Try with right arguments :\033[00m\n\n", 2);
	ft_putstr_fd("\033[38;5;46m ./fractol <mandelbrot>\033[00m\n", 2);
	ft_putstr_fd("\033[38;5;43m ./fractol <julia> <float> <float> \
		\033[00m\n", 2);
	ft_putstr_fd("\033[38;5;44m For more experience press <SPACE> in julia \
		\033[00m\n", 1);
	ft_putstr_fd("\033[38;5;48m ./fractol <burningship>\n\033[00m", 2);
	exit(EXIT_FAILURE);
}

int	select_fractal(t_fractol *fractol, int argc, char **argv)
{
	fractol->type = 0;
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0 && argc == 2)
		fractol->type = 1;
	else if (ft_strncmp(argv[1], "julia", 6) == 0 && argc == 4)
	{
		if (ft_isdigit(*argv[2]) && ft_isdigit(*argv[3]))
		{
			fractol->type = 2;
			fractol->julia_r = ft_atof(argv[2]);
			fractol->julia_i = ft_atof(argv[3]);
		}
		else
			print_helper();
	}
	else if (ft_strncmp(argv[1], "burningship", 12) == 0 && argc == 2)
		fractol->type = 3;
	else
		print_helper();
	return (1);
}

int	print_fractal(t_fractol *fractol)
{
	if (fractol->type == 1)
		draw_mandelbrot(fractol);
	else if (fractol->type == 2)
	{
		draw_julia(fractol);
		julia_moove(fractol);
	}
	else if (fractol->type == 3)
		draw_burningship(fractol);
	if (fractol->animate)
		fractol->flow = (fractol->flow + 1) % MAX_ITER;
	mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, fractol->img, 0, 0);
	return (1);
}
