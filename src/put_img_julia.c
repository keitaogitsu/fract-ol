/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:57:49 by kogitsu           #+#    #+#             */
/*   Updated: 2023/08/26 18:44:16 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	include_julia_set(t_complex z, t_complex c, int max_iter)
{
	int			i;
	t_complex	tmp;

	i = 0;
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

void	put_j(t_pixel_co *p_co, t_vars *vars, t_complex c, t_scr_co *new_scr)
{
	t_coord		val;
	t_coord		diff;
	t_complex	z;
	t_scr_co	tmp;

	if (vars->rate == 1.0)
	{
		diff.double_x = (XMAX - XMIN) / (double)NX;
		diff.double_y = (YMAX - YMIN) / (double)NY;
		val.double_x = XMIN + diff.double_x * (double)p_co->x;
		val.double_y = YMIN + diff.double_y * (double)p_co->y;
	}
	else
	{
		cursor_center_zoom_calc(vars, &tmp);
		screen_co_set(&tmp, new_scr);
		pixel_to_general(new_scr, &(p_co->x), &(p_co->y), &val);
	}
	z.real = val.double_x;
	z.imag = val.double_y;
	vars->num_of_calc = include_julia_set(z, c, MAX_ITER);
	put_color(vars, p_co);
}

void	mlx_put_img_julia(t_vars *vars)
{
	t_pixel_co	p_coord;
	t_complex	c;
	t_scr_co	new;

	p_coord.x = 0;
	p_coord.y = 0;
	c.real = vars->julia_parameter.double_x;
	c.imag = vars->julia_parameter.double_y;
	while (p_coord.y < NY)
	{
		p_coord.x = 0;
		while (p_coord.x < NX)
		{
			put_j(&p_coord, vars, c, &new);
			p_coord.x++;
		}
		p_coord.y++;
	}
	if (vars->rate != 1.0)
		screen_co_set(&new, vars->scr_co);
}
