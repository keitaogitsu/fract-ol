/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:22:46 by kogitsu           #+#    #+#             */
/*   Updated: 2023/07/17 17:58:12 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../minilibx-linux/mlx.h"
# include "../ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# define KEY_PRESS 2
# define ESC 53
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define ZOOMIN_RATE 0.8
# define ZOOMOUT_RATE 1.25
# define NX 500
# define NY 500
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

typedef struct s_coord {
	int	x;
	int	y;
}				t_coord;

typedef struct s_screen_coord {
	int	x0;
	int	x1;
	int	y0;
	int	y1;
}				t_screen_coord;


typedef struct s_vars {
	void			*mlx;
	void			*win;
	float			rate;
	t_data			*img;
	char			*fig_type;
	t_coord			*mouse_coord;
	t_screen_coord	screen_coord;
}				t_vars;

typedef struct s_complex {
	double	real;
	double	imag;
}				t_complex;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	mlx_put_img_mandelbrot(t_vars *vars);
double	my_sqrt(double x);
double	abs_complex(t_complex a);
void	mlx_put_img_julia(t_data *img, double c_real, double c_imag);
void	put_usage_description(void);
int		ft_strcmp(char *s1, char *s2);
void	clear_img(t_data *img);

#endif