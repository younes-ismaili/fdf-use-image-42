/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 20:12:14 by yismaili          #+#    #+#             */
/*   Updated: 2022/02/14 13:11:35 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "get_next_line.h"
# include "libft/libft.h"
# define W_WIDTH 2000
# define W_HEIGHT 1580
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_fdfs
{
	int		width;
	int		height;
	int		**matrix;
	void	*mlx_ptr;
	void	*win_ptr;
	int		zom;
	int		color;
	int		shift_x;
	int		shift_y;
	float	cos_x;
	float	sin_y;
	int		**color_map;
	int		z;
	int		z1;
	float	x;
	float	y;
	float	x1;
	float	y1;
	float	depth;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		switch_to;
}	t_fdf;

void	ft_read_maps(char *map_file, t_fdf *ptr);
int		ft_key(int key, t_fdf *p);
void	ft_drow(t_fdf *ptr);
int		ft_atohx(char *hex);
void	ft_bresenham(t_fdf *ptr);
char	*get_next_line(int fd);
char	*ft_read(int fd, char *left_str);
char	*get_next_line(int fd);
char	*ft_read(int fd, char *left_str);
char	*ft_next_str(char *left_str);
char	*ft_get_line(char *left_str);
void	my_mlx_pixel_put(t_fdf *ptr, int x, int y, int color);
void	invalid_file(void);
int		check(char *filename);
int		ft_close(int keycode);
void	ft_initialization(t_fdf *ptr);
float	ft_max(float a, float b);
int		ft_shift(int key, t_fdf *p);

#endif
