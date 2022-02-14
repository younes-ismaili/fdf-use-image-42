/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:20:22 by yismaili          #+#    #+#             */
/*   Updated: 2022/02/14 15:21:45 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check(char *filename)
{
	int		nb;
	int		fd;
	char	*buf;

	fd = open(filename, O_RDONLY);
	buf = malloc(sizeof(char) * 2);
	nb = read(fd, buf, 2);
	if (nb <= 0)
		return (1);
	free(buf);
	return (0);
}

void	invalid_file(void)
{
	ft_putstr_fd("invalid file\n", 1);
	exit(1);
}

int	ft_close(int keycode)
{
	if (keycode)
	{
		exit(1);
	}
	return (0);
}

float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

void	ft_initialization(t_fdf *ptr)
{
	if (ptr->height < 100 && ptr->width < 100)
		ptr->zom = 10;
	else
		ptr->zom = 2;
	ptr->cos_x = 0.523599;
	ptr->sin_y = 0.523599;
	ptr->depth = 2;
	ptr->shift_x = W_WIDTH / 2;
	ptr->shift_y = W_HEIGHT / 2 - 200;
	ptr->switch_to = 1;
}
