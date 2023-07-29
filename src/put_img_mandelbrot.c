/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 22:32:55 by kogitsu           #+#    #+#             */
/*   Updated: 2023/07/28 20:24:32 by kogitsu          ###   ########.fr       */
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
	double *x0, *x1, *y0, *y1;

	if (vars->rate == 1.0)
	{
		dx = (XMAX - XMIN) / (double)NX;
		dy = (YMAX - YMIN) / (double)NY;
		x = XMIN + dx * (double)*ix;
		y = YMIN + dy * (double)*iy;
	}
	else
	{
		x0 = vars->screen_coord->x0;
		x1 = vars->screen_coord->x1;
		y0 = vars->screen_coord->y0;
		y1 = vars->screen_coord->y1;
		*x0 = vars->rate * (*x0) + (1.0 - vars->rate) * vars->mouse_coord->x;
		*x1 = vars->rate * (*x1) + (1.0 - vars->rate) * vars->mouse_coord->x;
		*y0 = vars->rate * (*y0) + (1.0 - vars->rate) * vars->mouse_coord->y;
		*y1 = vars->rate * (*y1) + (1.0 - vars->rate) * vars->mouse_coord->y;
		// *(vars->screen_coord->x0) = vars->rate * *(vars->screen_coord->x0) + \
		// 						(1.0 - vars->rate) * vars->mouse_coord->x;
		// *(vars->screen_coord->x1) = vars->rate * *(vars->screen_coord->x1) + \
		// 						(1.0 - vars->rate) * vars->mouse_coord->x;
		// *(vars->screen_coord->y0) = vars->rate * *(vars->screen_coord->y0) + \
		// 						(1.0 - vars->rate) * vars->mouse_coord->y;
		// *(vars->screen_coord->y1) = vars->rate * *(vars->screen_coord->y1) + \
		// 						(1.0 - vars->rate) * vars->mouse_coord->y;
		// printf("x0:%lf|x1:%lf|y0:%lf|y1:%lf\n", vars->screen_coord->x0, vars->screen_coord->x1, vars->screen_coord->y0, vars->screen_coord->y1);
		dx = (*x1 - *x0) / (double)NX;
		dy = (*y1 - *y0) / (double)NY;
		x = *(vars->screen_coord->x0) + dx * (double)(*ix);
		y = *(vars->screen_coord->y0) + dy * (double)(*iy);
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
	printf("in mlx_put_img_mandelbrot: %f\n", *vars->screen_coord->x0);
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
