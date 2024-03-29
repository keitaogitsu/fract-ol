/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:21:33 by kogitsu           #+#    #+#             */
/*   Updated: 2023/08/27 18:53:55 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_color(t_vars *vars, t_pixel_co *p_co)
{
	if (vars->num_of_calc >= 30)
		my_mlx_pixel_put(vars->img, p_co->x, p_co->y, 0x008B0000);
	else if (vars->num_of_calc >= 10)
		my_mlx_pixel_put(vars->img, p_co->x, p_co->y, 0x00FF0000);
	else if (vars->num_of_calc >= 5)
		my_mlx_pixel_put(vars->img, p_co->x, p_co->y, 0x00FA8072);
	else if (vars->num_of_calc >= 3)
		my_mlx_pixel_put(vars->img, p_co->x, p_co->y, 0x00FFA07A);
	else if (vars->num_of_calc >= 2)
		my_mlx_pixel_put(vars->img, p_co->x, p_co->y, 0x00FFC0CB);
	else if (vars->num_of_calc >= 1)
		my_mlx_pixel_put(vars->img, p_co->x, p_co->y, 0x00FFFFFF);
}
