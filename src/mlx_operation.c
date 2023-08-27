/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:17:57 by kogitsu           #+#    #+#             */
/*   Updated: 2023/08/27 18:54:08 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	closemlx(t_vars *vars)
{
	if (vars->win != NULL && vars->mlx != NULL)
		exit (0);
	return (0);
}

int	keypress(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		if (vars->win != NULL && vars->win != NULL)
		{
			mlx_destroy_window(vars->mlx, vars->win);
			exit (0);
		}
	}
	vars = NULL;
	return (0);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	vars->mouse_co->double_x = (double)x;
	vars->mouse_co->double_y = (double)y;
	if (button == SCROLL_DOWN)
		vars->rate = ZOOMIN_RATE;
	else if (button == SCROLL_UP)
		vars->rate = ZOOMOUT_RATE;
	else
		vars->rate = 1.0;
	if (vars->rate != 1.0)
	{
		clear_img(vars->img);
		if (ft_strcmp(vars->fig_type, "m") == 0)
		{
			mlx_put_img_mandelbrot(vars);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
		}
		else if (ft_strcmp(vars->fig_type, "j") == 0)
		{
			mlx_put_img_julia(vars);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
		}
	}
	return (0);
}

int	rendering(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	return (0);
}

void	mlx_operation(t_vars *vars, t_data *img)
{
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);
	mlx_hook(vars->win, 17, 0, closemlx, vars);
	mlx_hook(vars->win, KEY_PRESS, 1L << 0, keypress, vars);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	mlx_expose_hook(vars->win, rendering, vars);
	mlx_loop(vars->mlx);
}
