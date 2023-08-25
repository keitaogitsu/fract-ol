/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:23:27 by kogitsu           #+#    #+#             */
/*   Updated: 2023/08/25 21:48:46 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdio.h>
#include <sys/time.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

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

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_data	img;
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
	vars.mlx = mlx_init();
	vars.img = &img;
	vars.mouse_co = &coord;
	vars.rate = 1.0;
	vars.scr_co = &s_coord;
	if (vars.mlx == NULL)
		return (1);
	vars.win = mlx_new_window(vars.mlx, NX, NY, "Fractol");
	img.img = mlx_new_image(vars.mlx, NX, NY);
	if (img.img == NULL)
		return (1);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	// init(&vars, &img);
	vars.rate = 1;

	printf("%f|%f\n", ft_atof(argv[2]), ft_atof(argv[3]));
	
	if ((argc == 3 && ft_strcmp(argv[1], "j") == 0) || \
		(argc == 2 && ft_strcmp(argv[1], "m") == 0))
	{
		if (ft_strcmp(argv[1], "j") == 0 && argc == 4)
		{
			vars.fig_type = "j";
			vars.julia_parameter.double_x = ft_atof(argv[2]);
			vars.julia_parameter.double_y = ft_atof(argv[3]);
			mlx_put_img_julia(&vars);
		}
		else if (ft_strcmp(argv[1], "m") == 0)
		{
			vars.fig_type = "m";
			mlx_put_img_mandelbrot(&vars);
		}
		else
		{
			put_usage_description();
			exit(1);
		}
		mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
		mlx_hook(vars.win, 17, 0, closemlx, &vars);
		mlx_hook(vars.win, KEY_PRESS, 1L << 0, keypress, &vars);
		mlx_mouse_hook(vars.win, mouse_hook, &vars);
		mlx_loop(vars.mlx);
		return (0);
	}
	else
	{
		put_usage_description();
		return (1);
	}
}
