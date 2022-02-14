/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 20:31:07 by yismaili          #+#    #+#             */
/*   Updated: 2022/02/14 13:15:29 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*ptr;

	if (argc != 2)
	{
		ft_putstr_fd("Usage : ./fdf path/to/map.fdf", 0);
		return (0);
	}
	ptr = (t_fdf *)malloc(sizeof(t_fdf));
	ft_read_maps(argv[1], ptr);
	ptr->mlx_ptr = mlx_init();
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, W_WIDTH, W_HEIGHT, "mlx42");
	ft_initialization(ptr);
	ptr->img = mlx_new_image(ptr->mlx_ptr, W_WIDTH, W_HEIGHT);
	ptr->addr = mlx_get_data_addr
		(ptr->img, &ptr->bits_per_pixel, &ptr->line_length, &ptr->endian);
	ft_drow(ptr);
	mlx_key_hook(ptr->win_ptr, ft_key, ptr);
	mlx_hook(ptr->win_ptr, 17, 2, ft_close, ptr);
	mlx_loop(ptr->mlx_ptr);
}
