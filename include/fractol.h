/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:22:46 by kogitsu           #+#    #+#             */
/*   Updated: 2023/07/09 16:50:45 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# define KEY_PRESS (2)
# define ESC (53)
# define NX 100;
# define NY 100;
# define XMIN -2.0;
# define YMIN -2.0;
# define XMAX  2.0;
# define YMAX  2.0;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_complex {
	double	real;
	double	imag;
}				t_complex;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	mlx_put_img(t_data *img);
double	my_sqrt(double x);
double	abs_complex(t_complex a);

#endif