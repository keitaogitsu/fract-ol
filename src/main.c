/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:23:27 by kogitsu           #+#    #+#             */
/*   Updated: 2023/07/29 19:37:56 by kogitsu          ###   ########.fr       */
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
	vars->mouse_coord->x = x;
	vars->mouse_coord->y = y;
	ft_printf("x:%d|y:%d\n", vars->mouse_coord->x, vars->mouse_coord->y);
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
			printf("%f\n", vars->screen_coord->x1);
			mlx_put_img_mandelbrot(vars);
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
	t_screen_coord s_coord;
	double x0 = 0.0;
	double x1 = 500.0;
	double y0 = 0.0;
	double y1 = 500.0;
	
	coord.x = 0;
	coord.y = 0;
	
	// vars.screen_coord = malloc(sizeof(t_screen_coord));
	s_coord.x0 = x0;
	s_coord.x1 = x1;
	s_coord.y0 = y0;
	s_coord.y1 = y1;
	if ((argc == 3 && ft_strcmp(argv[1], "j") == 0) || \
		(argc == 2 && ft_strcmp(argv[1], "m") == 0))
	{
		vars.mlx = mlx_init();
		vars.img = &img;
		vars.mouse_coord = &coord;
		vars.rate = 1.0;
		vars.screen_coord = &s_coord;
		if (vars.mlx == NULL)
			return (1);
		vars.win = mlx_new_window(vars.mlx, NX, NY, "Hello world!");
		img.img = mlx_new_image(vars.mlx, NX, NY);
		if (img.img == NULL)
			return (1);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
		&img.line_length, &img.endian);
		vars.rate = 1;
		if (ft_strcmp(argv[1], "j") == 0 && ft_strcmp(argv[2], "1") == 0)
		{
			vars.fig_type = "j";
			mlx_put_img_julia(&img, 0.4, -0.325);
		}
		else if (ft_strcmp(argv[1], "j") == 0 && ft_strcmp(argv[2], "2") == 0)
		{
			vars.fig_type = "j";
			mlx_put_img_julia(&img, -0.8, 0.156);
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


// int main(int argc, char **argv) {
//   struct timeval tv;
//   gettimeofday(&tv, NULL);
//   printf("%ld %06lu\n", tv.tv_sec, tv.tv_usec);
//   gettimeofday(&tv, NULL);
//   printf("%ld %06lu\n", tv.tv_sec, tv.tv_usec);
//   return 0;
// }