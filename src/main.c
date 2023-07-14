/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:23:27 by kogitsu           #+#    #+#             */
/*   Updated: 2023/07/13 11:59:18 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	closemlx(void *arg_vars)
{
	t_vars	*vars;

	vars = (t_vars *)arg_vars;
	if (vars->win != NULL && vars->mlx != NULL)
		exit (0);
	return (0);
}

int	keypress(int keycode, void	*arg_vars)
{
	t_vars	*vars;

	vars = (t_vars *)arg_vars;
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

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_data	img;

	if (argc == 2 && (*argv[1] == 'j' || *argv[1] == 'm'))
	{
		vars.mlx = mlx_init();
		if (vars.mlx == NULL)
			return (1);
		vars.win = mlx_new_window(vars.mlx, 800, 800, "Hello world!");
		img.img = mlx_new_image(vars.mlx, 800, 800);
		if (img.img == NULL)
			return (1);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
									&img.endian);
		if (*argv[1] == 'j')
			mlx_put_img_julia(&img, 0.4, -0.325);
		else if (argc == 2 && *argv[1] == 'm')
			mlx_put_img_mandelbrot(&img);
		mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
		mlx_hook(vars.win, 17, 0, closemlx, (void *)&vars);
		mlx_hook(vars.win, KEY_PRESS, 1L << 0, keypress, (void *)&vars);
		mlx_loop(vars.mlx);
		return (0);
	}
}
