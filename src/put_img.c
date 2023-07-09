/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 22:32:55 by kogitsu           #+#    #+#             */
/*   Updated: 2023/07/09 16:50:09 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

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

int	include_mandelbrot_set(t_complex c)
{
	int			i;
	t_complex	z;
	t_complex	tmp;

	i = 0;
	z.real = 0;
	z.imag = 0;
	while (i++ < 20)
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

void	mlx_put_img(t_data *img)
{
// 	my_mlx_pixel_put(img, 5, 5, 0x00FF0000);
// 	my_mlx_pixel_put(img, 10, 10, 0x00FF0000);
	int ix;
	int ix;
	float dx;
    float dy;

	dx = (XMAX - XMIN) / (double)NX;
	dy = (YMAX - YMIN) / (double)NY;
    for(int iy = 0; iy < NY; iy++) {
        for(int ix = 0; ix < NX; ix++) {
            float x = XMIN + dx*(double)ix;
            float y = YMIN + dy*(double)iy;
            complex<float> c(x, y);
            if(include_mandelbrot_set(c)) {
                cout << x << "  " << y << endl;
            }
        }
    }
}
