/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:50:57 by kogitsu           #+#    #+#             */
/*   Updated: 2023/07/17 16:25:15 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s2);
	while (i < len)
	{
		if (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
			i++;
		else if (s1[i] > s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
			return (1);
		else if (s1[i] < s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
			return (-1);
		else if (s1[i] == '\0' && s1[i] < s2[i])
			return (-1);
	}
	if (i == len)
	{
		if (s2[i] == '\0' && s2[i] < s1[i])
			return (1);
	}
	return (0);
}
