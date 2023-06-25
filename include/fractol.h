/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:22:46 by kogitsu           #+#    #+#             */
/*   Updated: 2023/06/25 18:52:15 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# define KEY_PRESS (2)
# define ESC (53)

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


#endif