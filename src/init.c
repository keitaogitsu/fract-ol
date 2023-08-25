/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 21:26:03 by kogitsu           #+#    #+#             */
/*   Updated: 2023/08/25 21:43:27 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdio.h>

void	init(t_vars	*vars, t_data *img)
{
    t_coord	coord;
	t_scr_co s_coord;
	double x0 = 0.0;
	double x1 = 500.0;
	double y0 = 0.0;
	double y1 = 500.0;
	
	coord.double_x = 0.0;
	coord.double_y = 0.0;
	s_coord.x0 = x0;
	s_coord.x1 = x1;
	s_coord.y0 = y0;
	s_coord.y1 = y1;
	vars->mouse_co = &coord;
	vars->rate = 1.0;
	vars->scr_co = &s_coord;
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		exit(1);
	vars->img = img;
    if (img->img == NULL)
		exit(1);
	vars->win = mlx_new_window(vars->mlx, NX, NY, "Fractol");
	img->img = mlx_new_image(vars->mlx, NX, NY);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
	&img->line_length, &img->endian);
}