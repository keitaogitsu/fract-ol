/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_coord_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:19:47 by kogitsu           #+#    #+#             */
/*   Updated: 2023/08/18 15:58:32 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdio.h>

void	screen_co_set(t_scr_co *src_screen, t_scr_co *dst_screen)
{
	dst_screen->x0 = src_screen->x0;
	dst_screen->x1 = src_screen->x1;
	dst_screen->y0 = src_screen->y0;
	dst_screen->y1 = src_screen->y1;
}
