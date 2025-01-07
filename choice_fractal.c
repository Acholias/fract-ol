/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:23:25 by lumugot           #+#    #+#             */
/*   Updated: 2025/01/07 10:44:37 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_helper(void)
{
	ft_putstr_fd("Arguments Inavlids !\n", 2);
	ft_putstr_fd("Try with right arguments :\n\n", 2);
	ft_putstr_fd(" ./fractol <mandelbrot>\n", 2);
	ft_putstr_fd(" ./fractol <julia> <float> <float>\n", 2);
	ft_putstr_fd("For more experience press <SPACE> in julia", 1);
	ft_putstr_fd(" ./fractol <burningship>\n", 2);
}

void	print_fractal(t_fractol *fractol)
{
	if (fractol->type == 1)
		draw_mandelbrot(fractol);
	else if (fractol->type == 2)
		draw_julia(fractol);
	else if (fractol->type == 3)
		draw_burningship(fractol);
}

int	select_fractal(t_fractol *fractol, int argc, char **argv)
{
	fractol->type = 0;
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0 && argc == 2)
		fractol->type = 1;
	else if (ft_strncmp(argv[1], "julia", 6) == 0 && argc == 4)
	{
		fractol->type = 2;
		fractol->julia_r = ft_atof(argv[2]);
		fractol->julia_i = ft_atof(argv[3]);
	}
	else if (ft_strncmp(argv[1], "burningship", 12) == 0 && argc == 2)
		fractol->type = 3;
	else
	{
		print_helper();
		exit(EXIT_FAILURE);
	}
	return (1);
}
