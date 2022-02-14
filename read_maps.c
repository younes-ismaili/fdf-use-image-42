/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 21:53:55 by yismaili          #+#    #+#             */
/*   Updated: 2022/02/13 18:33:21 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *map_file)
{
	int		fd;
	int		height;
	char	*get_line;

	fd = open(map_file, O_RDONLY);
	height = 0;
	get_line = get_next_line(fd);
	while (get_line)
	{
		get_line = get_next_line(fd);
		height ++;
	}
	free(get_line);
	close(fd);
	return (height);
}

int	get_width(char *map_file)
{
	int		fd;
	char	**words;
	int		width;
	char	*get_line;
	int		i;

	width = 0;
	fd = open (map_file, O_RDONLY);
	get_line = get_next_line(fd);
	words = ft_split(get_line, ' ');
	while (words[width])
	{
		width++;
	}
	close(fd);
	free(get_line);
	i = 0;
	while (words[i])
		free(words[i++]);
	free(words);
	return (width);
}

void	ft_tofillup(int *m_line, int *color, char *g_line)
{
	char	**num;
	int		i;
	int		k;
	int		j;

	i = 0;
	num = ft_split(g_line, ' ');
	while (num[i])
	{
		m_line[i] = ft_atoi(num[i]);
		k = 0;
		while (num[i][k] && num[i][k] != ',')
			k++;
		if (num[i][k++] == ',')
			color[i] = ft_atohx(&num[i][k]);
		else
			color[i] = 0xffffff;
		i++;
	}
	j = 0;
	while (num[j])
		free(num[j++]);
	free(num);
}

void	ft_read_maps(char *map_file, t_fdf *ptr)
{
	int		fd;
	int		i;
	char	*get_line;

	i = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0 || check(map_file))
		invalid_file();
	ptr->height = get_height(map_file);
	ptr->width = get_width(map_file);
	ptr->matrix = (int **) malloc(sizeof(int *) * (ptr->height + 1));
	ptr->color_map = (int **) malloc(sizeof(int *) * (ptr->height + 1));
	while (i < ptr->height)
	{
		ptr->matrix[i] = (int *) malloc(sizeof (int) * ptr->width);
		ptr->color_map[i] = (int *) malloc(sizeof(int) * ptr->width);
		get_line = get_next_line(fd);
		ft_tofillup(ptr->matrix[i], ptr->color_map[i], get_line);
		free(get_line);
		i++;
	}
	ptr->matrix[i] = NULL;
	ptr->color_map[i] = NULL;
	close(fd);
}
