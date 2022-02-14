/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:26:17 by yismaili          #+#    #+#             */
/*   Updated: 2022/02/14 13:14:09 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_key(int key, t_fdf *p)
{
	if (key == 6)
		p->zom += 2;
	if (key == 7)
		p->zom -= 2;
	if (key == 87)
		p->cos_x += 0.2;
	if (key == 84)
		p->cos_x += 0.2;
	if (key == 8)
		p->depth += 5;
	if (key == 9)
		p->depth -= 5;
	if (key == 53)
		ft_close(key);
	ft_shift(key, p);
	mlx_destroy_image(p->mlx_ptr, p->img);
	p->img = mlx_new_image(p->mlx_ptr, W_WIDTH, W_HEIGHT);
	ft_drow(p);
	return (0);
}

int	ft_atohx(char *hex)
{
	int	length;
	int	base;
	int	decimal;

	length = ft_strlen(hex) - 1;
	base = 1;
	decimal = 0;
	while (length >= 0)
	{
		if (hex[length] >= '0' && hex[length] <= '9')
			decimal += (hex[length] - 48) * base;
		if (hex[length] >= 'A' && hex[length] <= 'F')
			decimal += (hex[length] - 55) * base;
		if (hex[length] >= 'a' && hex[length] <= 'f')
			decimal += (hex[length] - 87) * base;
		base *= 16;
		length--;
	}
	return (decimal);
}

void	my_mlx_pixel_put(t_fdf *ptr, int x, int y, int color)
{
	char	*dst;

	if (x > 0 && y > 0 && x < W_WIDTH && y < W_HEIGHT)
	{
		dst = ptr->addr + (y * ptr->line_length + x
				* (ptr->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

int	ft_shift(int key, t_fdf *p)
{
	if (key == 125)
		p->shift_y += 20;
	if (key == 126)
		p->shift_y -= 20;
	if (key == 124)
		p->shift_x += 20;
	if (key == 123)
		p->shift_x -= 20;
	if (key == 1)
		p->switch_to = 0;
	if (key == 2)
		p->switch_to = 1;
	return (0);
}
