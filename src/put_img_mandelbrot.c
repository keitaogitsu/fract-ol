/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 22:32:55 by kogitsu           #+#    #+#             */
/*   Updated: 2023/07/17 17:52:35 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdio.h>

static int	include_mandelbrot_set(t_complex c, int max_iter)
{
	int			i;
	t_complex	z;
	t_complex	tmp;

	i = 0;
	z.real = 0;
	z.imag = 0;
	while (i++ < max_iter)
	{
		if (abs_complex(z) > 2.0)
			return (0);
		tmp.real = z.real;
		tmp.imag = z.imag;
		z.real = tmp.real * tmp.real - tmp.imag * tmp.imag + c.real;
		z.imag = 2 * tmp.real * tmp.imag + c.imag;
	}
	return (1);
}

static void	put_mandelbrot(int *ix, int *iy, t_vars *vars)
{
	double		x;
	double		y;
	double		dx;
	double		dy;
	t_complex	c;
	static double		x_max = XMAX;
	static double		x_min = XMIN;
	static double		y_max = YMAX;
	static double		y_min = YMIN;

	if (vars->rate == 1.0)
	{
		dx = (XMAX - XMIN) / (double)NX;
		dy = (YMAX - YMIN) / (double)NY;
		x = XMIN + dx * (double)*ix;
		y = YMIN + dy * (double)*iy;
	}
	else
	{
		x_min = vars->rate * x_min + (1.0 - vars->rate) * vars->mouse_coord->x;
		x_max = vars->rate * x_max + (1.0 - vars->rate) * vars->mouse_coord->x;
		y_min = vars->rate * y_min + (1.0 - vars->rate) * vars->mouse_coord->y;
		y_max = vars->rate * y_max + (1.0 - vars->rate) * vars->mouse_coord->y;
		printf("x_min:%lf|x_max:%lf|y_min:%lf|y_max:%lf\n", x_min, x_max, y_min, y_max);
		dx = (x_max - x_min) / (double)NX;
		dy = (y_max - y_min) / (double)NY;
		x = x_min + dx * (double)(*ix);
		y = y_min + dy * (double)(*iy);
	}
	c.real = x;
	c.imag = y;
	if (!include_mandelbrot_set(c, MAX_ITER))
		my_mlx_pixel_put(vars->img, *ix, *iy, 0x00FF0000);
}

void	mlx_put_img_mandelbrot(t_vars *vars)
{
	int		ix;
	int		iy;

	ix = 0;
	iy = 0;
	printf("in mlx_put_img_mandelbrot: %f\n", vars->rate);
	while (iy < NY)
	{
		ix = 0;
		while (ix < NX)
		{
			put_mandelbrot(&ix, &iy, vars);
			ix++;
		}
		iy++;
	}
}
