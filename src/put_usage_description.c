/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_usage_description.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:11:12 by kogitsu           #+#    #+#             */
/*   Updated: 2023/08/26 12:42:34 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	put_usage_description(void)
{
	ft_printf("実行する場合は\n\n<例>\n./fractol m\n./fractol j 0.4 -0.325 \
			\n\nのように入力してください。\n");
	ft_printf("実行ファイルのオプションは1つもしくは3つになります。\n\n");
	ft_printf("オプションの1つ目は、「m」か「j」を入力してください。\n");
	ft_printf("「m」がマンデブロ集合を、「j」がジュリア集合を表示します。\n\n");
	ft_printf("1つ目のオプションが「j」だった場合、\
			\n2つ目と3つ目のオプションを入力してください。\n");
	ft_printf("この場合、\n(0.4, 0.325),\n(-0.8, 0.156),\n(-0.3, -0.63) \
			\nなどの組み合わせを入力すると綺麗な図形が表示されます。\n");
	exit(1);
}
