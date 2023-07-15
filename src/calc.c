/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:41:05 by kogitsu           #+#    #+#             */
/*   Updated: 2023/07/15 13:41:44 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double	my_sqrt(double x)
{
	int		i;
	double	y;

	if (x == 0)
		return (0);
	else
	{
		y = 1;
		i = 0;
		while (i++ < 10)
			y = (y + x / y) / 2;
		return (y);
	}
}

double	abs_complex(t_complex a)
{
	double	abs;

	abs = my_sqrt(a.real * a.real + a.imag * a.imag);
	return (abs);
}