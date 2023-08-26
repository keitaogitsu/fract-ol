/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:23:27 by kogitsu           #+#    #+#             */
/*   Updated: 2023/08/26 18:43:17 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdio.h>

static void	j_m_judge(char **argv, t_vars *vars, int *error_flag)
{
	if (ft_strcmp(argv[1], "j") == 0)
	{
		vars->fig_type = "j";
		vars->julia_parameter.double_x = ft_atof(argv[2], error_flag);
		vars->julia_parameter.double_y = ft_atof(argv[3], error_flag);
		if (!(*error_flag))
			mlx_put_img_julia(vars);
		else
			put_usage_description();
	}
	else if (ft_strcmp(argv[1], "m") == 0)
	{
		vars->fig_type = "m";
		mlx_put_img_mandelbrot(vars);
	}
	else
		put_usage_description();
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_data	img;
	int		error_flag;

	error_flag = 0;
	init(&vars, &img);
	if ((argc == 4 && ft_strcmp(argv[1], "j") == 0) || \
		(argc == 2 && ft_strcmp(argv[1], "m") == 0))
	{
		j_m_judge(argv, &vars, &error_flag);
		mlx_operation(&vars, &img);
		free(vars.mouse_co);
		free(vars.scr_co);
		return (0);
	}
	else
	{
		put_usage_description();
		free(vars.mouse_co);
		free(vars.scr_co);
		return (1);
	}
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q fractol");
// }
