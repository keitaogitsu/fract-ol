/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_coord_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:19:47 by kogitsu           #+#    #+#             */
/*   Updated: 2023/08/06 19:42:09 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdio.h>

void	screen_co_set(t_scr_co *src_screen, t_scr_co *dst_screen)
{
	// printf("x0:%lf|x1:%lf|y0:%lf|y1:%lf\n", src_screen->x0, src_screen->x1, src_screen->y0, src_screen->y1);
	dst_screen->x0 = src_screen->x0;
	dst_screen->x1 = src_screen->x1;
	dst_screen->y0 = src_screen->y0;
	dst_screen->y1 = src_screen->y1;
}
