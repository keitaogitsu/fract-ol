/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:38:50 by kogitsu           #+#    #+#             */
/*   Updated: 2023/07/17 17:38:08 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdio.h>

void	clear_img(t_data *img)
{
	int	ix;
	int	iy;

	ix = 0;
	iy = 0;
	printf("42tokyo\n");
	while (iy < NY)
	{
		ix = 0;
		while (ix < NX)
		{
			my_mlx_pixel_put(img, ix, iy, 0);
			ix++;
		}
		iy++;
	}
}
