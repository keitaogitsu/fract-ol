/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 22:32:55 by kogitsu           #+#    #+#             */
/*   Updated: 2023/08/27 14:57:58 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

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
			return (i);
		tmp.real = z.real;
		tmp.imag = z.imag;
		z.real = tmp.real * tmp.real - tmp.imag * tmp.imag + c.real;
		z.imag = 2 * tmp.real * tmp.imag + c.imag;
	}
	return (0);
}

void	put_mandelbrot(t_pixel_co *p_co, t_vars *vars, t_scr_co *new_scr)
{
	t_coord		val;
	t_complex	c;
	t_scr_co	tmp;
	t_coord		diff;

	if (vars->rate == 1.0)
	{
		diff.double_x = (XMAX - XMIN) / (double)NX;
		diff.double_y = (YMAX - YMIN) / (double)NY;
		val.double_x = XMIN + diff.double_x * (double)p_co->x;
		val.double_y = -(YMIN + diff.double_y * (double)p_co->y);
	}
	else
	{
		cursor_center_zoom_calc(vars, &tmp);
		screen_co_set(&tmp, new_scr);
		pixel_to_general(new_scr, &(p_co->x), &(p_co->y), &val);
	}
	c.real = val.double_x;
	c.imag = val.double_y;
	vars->num_of_calc = include_mandelbrot_set(c, MAX_ITER);
	put_color(vars, p_co);
}

void	mlx_put_img_mandelbrot(t_vars *vars)
{
	t_pixel_co	p_coord;
	t_scr_co	new;

	p_coord.x = 0;
	p_coord.y = 0;
	while (p_coord.y < NY)
	{
		p_coord.x = 0;
		while (p_coord.x < NX)
		{
			put_mandelbrot(&p_coord, vars, &new);
			p_coord.x++;
		}
		p_coord.y++;
	}
	if (vars->rate != 1.0)
		screen_co_set(&new, vars->scr_co);
}
