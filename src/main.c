/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:23:27 by kogitsu           #+#    #+#             */
/*   Updated: 2023/07/15 17:25:50 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

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

int	mouse_hook(int keycode, t_vars *vars)
{
	vars = (t_vars *)vars;

	ft_printf("%d\n", keycode);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_data	img;

	if ((argc == 3 && *argv[1] == 'j' && ft_strlen(argv[1]) == 1) \
	|| (argc == 2 && *argv[1] == 'm' && ft_strlen(argv[1]) == 1))
	{
		vars.mlx = mlx_init();
		if (vars.mlx == NULL)
			return (1);
		vars.win = mlx_new_window(vars.mlx, 800, 800, "Hello world!");
		img.img = mlx_new_image(vars.mlx, 800, 800);
		if (img.img == NULL)
			return (1);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
		&img.line_length, &img.endian);
		if (*argv[1] == 'j' && *argv[2] == '1' && ft_strlen(argv[2]) == 1)
			mlx_put_img_julia(&img, 0.4, -0.325);
		else if (*argv[1] == 'j' && *argv[2] == '2' && ft_strlen(argv[2]) == 1)
			mlx_put_img_julia(&img, -0.8, 0.156);
		else if (*argv[1] == 'm')
			mlx_put_img_mandelbrot(&img);
		else
		{
			put_usage_description();
			exit(1);
		}

		mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
		mlx_hook(vars.win, 17, 0, closemlx, (void *)&vars);
		mlx_hook(vars.win, KEY_PRESS, 1L << 0, keypress, (void *)&vars);
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
