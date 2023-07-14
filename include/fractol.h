/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:22:46 by kogitsu           #+#    #+#             */
/*   Updated: 2023/07/13 13:04:30 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../minilibx-linux/mlx.h"
# include "../ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# define KEY_PRESS (2)
# define ESC (53)
# define NX 800
# define NY 800
# define XMIN -2.0
# define YMIN -2.0
# define XMAX 2.0
# define YMAX 2.0
# define MAX_ITER 100

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
	float	real;
	float	imag;
}				t_complex;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	mlx_put_img_mandelbrot(t_data *img);
double	my_sqrt(double x);
double	abs_complex(t_complex a);
void	mlx_put_img_julia(t_data *img, float c_real, float c_imag);

#endif