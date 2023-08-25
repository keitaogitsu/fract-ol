/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:42:39 by kogitsu           #+#    #+#             */
/*   Updated: 2023/08/25 19:17:54 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

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
            ret *= x;
        return ret;
    }
    else
    {
        y *= -1;
        small = 1.0 / x;
        while (i++ < y)
            ret *= small;
        return ret;
    }
}

static void	expo_support(char *num_ptr, double *value)
{
	double psign;
	double p;

	num_ptr++;
	psign = +1.0;
	if (*num_ptr == '+')
		num_ptr++;
	else if (*num_ptr == '-')
	{
		psign = -1.0;
		num_ptr++;
	}
	p = 0.0;
	while (ft_isdigit((unsigned char) *num_ptr))
	{
		p = p * 10.0 + (*num_ptr - '0');
		num_ptr++;
	}
	*value *= lpow(10.0, psign * p);
}

static void decimal_point_support(int *valid, char **num_ptr, double *value)
{
	double small;
	
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

double  ft_atof(char *num_ptr)
{
    int		valid;
    double	value;
    double	sign;
    
    valid = 0;
    value = 0.0;
    sign = 1.0;
    if (*num_ptr == '+')
        num_ptr++;
    else if (*num_ptr == '-')
    {
        sign = -1.0;
        num_ptr++;
    }
    while (ft_isdigit((unsigned char)*num_ptr))
    {
        valid = 1;
        value = value * 10.0 + (*num_ptr - '0');
        num_ptr++;
    }
    if (*num_ptr == '.')
		decimal_point_support(&valid, &num_ptr, &value);
    if (valid && (*num_ptr == 'e' || *num_ptr == 'E'))
		expo_support(num_ptr, &value);
    return sign * value;
}


// int main(void)
// {
//     char s1[] = "123.45";
//     char s2[] = "-4567.89";
//     char s3[] = "5.4321e-2";
//     char s4[] = "5.4321e+2";

//     printf("ft_atof(%s) = %lf\n", s1, ft_atof(s1));
//     printf("ft_atof(%s) = %lf\n", s2, ft_atof(s2));
//     printf("ft_atof(%s) = %lf\n", s3, ft_atof(s3));
//     printf("ft_atof(%s) = %lf\n", s4, ft_atof(s4));
//     return 0;
// }
