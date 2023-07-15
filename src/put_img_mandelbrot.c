/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 22:32:55 by kogitsu           #+#    #+#             */
/*   Updated: 2023/07/15 14:16:58 by kogitsu          ###   ########.fr       */
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

static void	put_mandelbrot(int *ix, int *iy, t_data *img)
{
	float		x;
	float		y;
	float		dx;
	float		dy;
	t_complex	c;

	dx = (XMAX - XMIN) / (double)NX;
	dy = (YMAX - YMIN) / (double)NY;
	x = XMIN + dx * (double)*ix;
	y = YMIN + dy * (double)*iy;
	c.real = x;
	c.imag = y;
	printf("x,y = %f, %f\n", c.real, c.imag);
	if (!include_mandelbrot_set(c, MAX_ITER))
		my_mlx_pixel_put(img, *ix, *iy, 0x00FF0000);
}

void	mlx_put_img_mandelbrot(t_data *img)
{
	int		ix;
	int		iy;

	ix = 0;
	iy = 0;
	while (iy < NY)
	{
		ix = 0;
		while (ix < NX)
		{
			put_mandelbrot(&ix, &iy, img);
			ix++;
		}
		iy++;
	}
}
