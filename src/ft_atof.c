/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:42:39 by kogitsu           #+#    #+#             */
/*   Updated: 2023/08/26 18:40:33 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static double	lpow(long x, long y)
{
	double	ret;
	int		i;
	double	small;

	ret = 1;
	i = 0;
	if (y > 0)
	{
		while (i++ < y)
			ret *= (double)x;
		return (ret);
	}
	else
	{
		y *= -1;
		small = 1.0 / (double)x;
		while (i++ < y)
			ret *= small;
		return (ret);
	}
}

static void	integer_part_support(char **num_ptr, int *valid, double *value)
{
	while (ft_isdigit((unsigned char)**num_ptr))
	{
		*valid = 1;
		*value = *value * 10.0 + (**num_ptr - '0');
		(*num_ptr)++;
	}
}

static void	decimal_point_support(int *valid, char **num_ptr, double *value)
{
	double	small;

	*valid = 0;
	(*num_ptr)++;
	if (ft_isdigit((unsigned char)**num_ptr))
	{
		small = 0.1;
		*valid = 1;
		while (ft_isdigit((unsigned char)**num_ptr))
		{
			*value += small * (**num_ptr - '0');
			small *= 0.1;
			(*num_ptr)++;
		}
	}
}

static void	expo_support(char **num_ptr, double *value)
{
	double	psign;
	double	p;

	(*num_ptr)++;
	psign = +1.0;
	if (**num_ptr == '+')
		(*num_ptr)++;
	else if (**num_ptr == '-')
	{
		psign = -1.0;
		(*num_ptr)++;
	}
	p = 0.0;
	while (ft_isdigit((unsigned char) **num_ptr))
	{
		p = p * 10.0 + (**num_ptr - '0');
		(*num_ptr)++;
	}
	*value *= lpow(10.0, psign * p);
}

double	ft_atof(char *num_ptr, int *error_flag)
{
	int		valid;
	double	value;
	double	sign;

	valid = 0;
	value = 0.0;
	sign = 1.0;
	if (*num_ptr == '+' || *num_ptr == '-')
	{
		if (*num_ptr == '-')
			sign = -1.0;
		num_ptr++;
	}
	integer_part_support(&num_ptr, &valid, &value);
	if (*num_ptr == '.')
		decimal_point_support(&valid, &num_ptr, &value);
	if (valid && (*num_ptr == 'e' || *num_ptr == 'E'))
		expo_support(&num_ptr, &value);
	if (sign * value != (double)-1 && *num_ptr != '\0')
	{
		*error_flag = 1;
		return (-1);
	}
	else
		return (sign * value);
}

// #include <stdio.h>

// int main(void)
// {
//     char s1[] = "123.45";
//     char s2[] = "-4567.89";
//     char s3[] = "5.4321e-2";
//     char s4[] = "5.4321e+2";
//     char s5[] = "5.4321e+2aaa";
// 	int a = 0;

//     printf("ft_atof(%s) = %lf\n", s1, ft_atof(s1, &a));
//     printf("ft_atof(%s) = %lf\n", s2, ft_atof(s2, &a));
//     printf("ft_atof(%s) = %lf\n", s3, ft_atof(s3, &a));
//     printf("ft_atof(%s) = %lf\n", s4, ft_atof(s4, &a));
//     printf("ft_atof(%s) = %lf\n", s5, ft_atof(s5, &a));
//     return 0;
// }
