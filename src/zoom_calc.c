/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:41:17 by kogitsu           #+#    #+#             */
/*   Updated: 2023/09/02 16:37:43 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	cursor_center_zoom_calc(t_vars *vars, t_scr_co *tmp)
{
	tmp->x0 = vars->rate * vars->scr_co->x0 + \
						(1.0 - vars->rate) * (NX / 2.0);
	tmp->x1 = vars->rate * vars->scr_co->x1 + \
						(1.0 - vars->rate) * (NX / 2.0);
	tmp->y0 = vars->rate * vars->scr_co->y0 + \
						(1.0 - vars->rate) * (NY / 2.0);
	tmp->y1 = vars->rate * vars->scr_co->y1 + \
						(1.0 - vars->rate) * (NY / 2.0);
}

void	pixel_to_general(t_scr_co *new_scr_co, int *ix, int *iy, t_coord *val)
{
	t_coord	diff;

	diff.double_x = (new_scr_co->x1 - new_scr_co->x0) / (double)NX;
	diff.double_y = (new_scr_co->y1 - new_scr_co->y0) / (double)NY;
	val->double_x = (new_scr_co->x0 + diff.double_x * (double)(*ix)) \
					/ (NX / 4.0) - 2.0;
	val->double_y = -(new_scr_co->y0 + diff.double_y * (double)(*iy)) \
					/ (NY / 4.0) + 2.0;
}
