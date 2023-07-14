/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 22:32:55 by kogitsu           #+#    #+#             */
/*   Updated: 2023/07/13 11:30:11 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdio.h>

double	my_sqrt(double x)
{
	int		i;
	double	y;

	if (x == 0)
		return (0);
	else
	{
		y = 1;
		i = 0;
		while (i++ < 10)
			y = (y + x / y) / 2;
		return (y);
	}
}

double	abs_complex(t_complex a)
{
	double	abs;

	abs = my_sqrt(a.real * a.real + a.imag * a.imag);
	return (abs);
}

int	include_mandelbrot_set(t_complex c, int max_iter)
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

void	mlx_put_img_mandelbrot(t_data *img)
{

	int ix;
	int iy;
	float dx;
    float dy;
    float x;
    float y;
    t_complex c;

    ix = 0;
    iy = 0;
	dx = (XMAX - XMIN) / (double)NX;
	dy = (YMAX - YMIN) / (double)NY;
    while (iy < NY)
    {
        ix = 0;
        while (ix < NX)
        {
            x = XMIN + dx * (double)ix;
            y = YMIN + dy * (double)iy;
            c.real = x;
            c.imag = y;
            printf("x,y = %f, %f\n", c.real, c.imag);
            if (!include_mandelbrot_set(c, MAX_ITER))
                my_mlx_pixel_put(img, ix, iy, 0x00FF0000);
            ix++;
        }
        iy++;
    }
}
