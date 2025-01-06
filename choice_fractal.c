/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:23:25 by lumugot           #+#    #+#             */
/*   Updated: 2024/12/24 23:47:47 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_helper(void)
{
	ft_putstr_fd("Arguments Inavlids !\n", 2);
	ft_putstr_fd("Try with right arguments :\n\n", 2);
	ft_putstr_fd(" ./fractol <mandelbrot>\n\n", 2);
	ft_putstr_fd(" ./fractol <julia> <value1> <value2>\n", 2);
	ft_putstr_fd(" For julia try with this: \n", 2);
	ft_putstr_fd("- Example 1: <value> <value> \n", 2);
	ft_putstr_fd("- Example 2: <value> <value> \n", 2);
	ft_putstr_fd("- Example 3: <value> <value> \n\n", 2);
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
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0 && argc == 2)
		fractol->type = 1;
	else if (ft_strncmp(argv[1], "julia", 5) == 0 && argc == 4)
	{
		fractol->type = 2;
		fractol->julia_r = ft_atof(argv[2]);
		fractol->julia_i = ft_atof(argv[3]);
	}
	else if (ft_strncmp(argv[1], "burningship", 11) == 0 && argc == 2)
		fractol->type = 3;
	else
	{
		print_helper();
		exit(EXIT_FAILURE);
	}
	return (1);
}
