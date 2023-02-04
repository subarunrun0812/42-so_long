/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subarunrun <subarunrun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:01:40 by subarunrun        #+#    #+#             */
/*   Updated: 2023/02/04 16:39:19 by subarunrun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_upperlower(char *width)
{
	size_t	i;

	i = 0;
	while (width[i])
	{
		if (width[i] != '1')
			error(MAP_ERROR);
		i++;
	}
}

void	check_map_wall(t_map *map)
{
	int	i;

	i = 0;
	check_map_upperlower(map->map_data[i]);
	i++;
	while (i < map->vertical - 1)
	{
		if (map->map_data[i][0] != '1' ||
			map->map_data[i][map->width - 1] != '1')
			error(MAP_ERROR);
		i++;
	}
	check_map_upperlower(map->map_data[i]);
}

void	count_special_words(t_num *num, t_map *map)
{
	int		y;
	int		x;

	y = 1;
	while (y < map->vertical)
	{
		x = 1;
		while (x < map->width)
		{
			if (map->map_data[y][x] != '0' && map->map_data[y][x] != '1' &&
				map->map_data[y][x] != 'C' && map->map_data[y][x] != 'E' &&
				map->map_data[y][x] != 'P' && map->map_data[y][x] != 'N')
				error(MAP_ERROR);
			if (map->map_data[y][x] == 'C')
				num->c_num++;
			if (map->map_data[y][x] == 'E')
				num->e_num++;
			if (map->map_data[y][x] == 'P')
				num->p_num++;
			x++;
		}
		y++;
	}
	return ;
}

void	check_map_char(t_map *map)
{
	t_num	*num;

	num = (t_num *)malloc(sizeof(t_num));
	num->c_num = 0;
	num->e_num = 0;
	num->p_num = 0;
	count_special_words(num, map);
	if (num->c_num < 1 || num->e_num != 1 || num->p_num != 1)
		error(MAP_ERROR);
	return ;
}

void	check_map(t_map *map)
{
	if (map->vertical < 3 || map->width < 3)
		error(MAP_ERROR);
	check_map_char(map);
	check_map_wall(map);
	check_goal(map);
}
