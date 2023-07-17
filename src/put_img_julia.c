/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:57:49 by kogitsu           #+#    #+#             */
/*   Updated: 2023/07/17 13:07:51 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/fractol.h"
#include <stdio.h>


static int	include_julia_set(t_complex z, t_complex c, int max_iter)
{
	int			i;
	t_complex	tmp;

	i = 0;
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

static void	put_julia(int *ix, int *iy, t_data *img, t_complex c)
{
	double		dx;
	double		dy;
	double		x;
	double		y;
	t_complex	z;

	dx = (XMAX - XMIN) / (double)NX;
	dy = (YMAX - YMIN) / (double)NY;
	x = XMIN + dx * (double)*ix;
	y = YMIN + dy * (double)*iy;
	z.real = x;
	z.imag = y;
	if (include_julia_set(z, c, MAX_ITER))
		my_mlx_pixel_put(img, *ix, *iy, 0x00FF0000);
}

void	mlx_put_img_julia(t_data *img, double c_real, double c_imag)
{
	int			ix;
	int			iy;
	t_complex	c;

	ix = 0;
	iy = 0;
	c.real = c_real;
	c.imag = c_imag;
	while (iy < NY)
	{
		ix = 0;
		while (ix < NX)
		{
			put_julia(&ix, &iy, img, c);
			ix++;
		}
		iy++;
	}
}
