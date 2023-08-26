/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 21:26:03 by kogitsu           #+#    #+#             */
/*   Updated: 2023/08/26 17:14:58 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdio.h>
#include <stdlib.h>

void	init(t_vars	*vars, t_data *img)
{
	vars->rate = 1;
	vars->mouse_co = (t_coord *)malloc(sizeof(t_coord) * 1);
	vars->scr_co = (t_scr_co *)malloc(sizeof(t_scr_co) * 1);
	if (vars->mouse_co == NULL || vars->scr_co == NULL)
		exit(1);
	vars->scr_co->x0 = 0.0;
	vars->scr_co->x1 = 500.0;
	vars->scr_co->y0 = 0.0;
	vars->scr_co->y1 = 500.0;
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		exit(1);
	vars->img = img;
	vars->win = mlx_new_window(vars->mlx, NX, NY, "Fractol");
	img->img = mlx_new_image(vars->mlx, NX, NY);
	if (img->img == NULL)
		exit(1);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
	&img->line_length, &img->endian);
}
