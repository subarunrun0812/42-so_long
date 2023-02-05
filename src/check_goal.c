/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_goal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subarunrun <subarunrun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:33:27 by subarunrun        #+#    #+#             */
/*   Updated: 2023/01/30 22:30:24 by subarunrun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	**map_init(t_map *map)
{
	int		**map_c;
	int		i;

	map_c = (int **)malloc(sizeof(int *) * map->vertical);
	if (!map_c)
		error_map(map->map_data, map->vertical, MALLOC_ERROR);
	i = 0;
	while (i < map->vertical)
	{
		map_c[i] = (int *)malloc(sizeof(int) * map->width);
		if (!map_c[i])
		{
			free_mapdata_int(map_c, map->vertical);
			error_map(map->map_data, map->vertical, MALLOC_ERROR);
		}
		ft_bzero(map_c[i], sizeof(int) * map->width);
		i++;
	}
	return (map_c);
}

void	player_spot(t_map *map, int *y, int *x)
{
	*y = 0;
	while (*y < map->vertical)
	{
		*x = 0;
		while (*x < map->width)
		{
			if (map->map_data[*y][*x] == 'P')
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

void	goal_nav(t_map *map, int **map_c, int y, int x)
{
	while (map_c[y][x] != 1 && map->map_data[y][x] != '1'
			&& map->map_data[y][x] != 'N')
	{
		map_c[y][x] = 1;
		if (y > 0 && y + 1 < map->vertical && x > 0 && x + 1 < map->width)
		{
			goal_nav(map, map_c, y - 1, x);
			goal_nav(map, map_c, y, x - 1);
			goal_nav(map, map_c, y + 1, x);
			goal_nav(map, map_c, y, x + 1);
		}
	}
	return ;
}

int	check_goal_nav(t_map *map, int **map_c)
{
	int	y;
	int	x;
	int	flag;

	y = 1;
	flag = 1;
	while (y < map->vertical)
	{
		x = 1;
		while (x < map->width)
		{
			if ((map->map_data[y][x] == 'C' || map->map_data[y][x] == 'E')
				&& map_c[y][x] != 1)
				return (1);
			if (map->map_data[y][x] == 'E' && map_c[y][x] == 1)
				flag = 0;
			x++;
		}
		y++;
	}
	return (flag);
}

void	check_goal(t_map *map)
{
	int		**map_c;
	int		y;
	int		x;

	y = 0;
	x = 0;
	map_c = map_init(map);
	player_spot(map, &y, &x);
	goal_nav(map, map_c, y, x);
	if (check_goal_nav(map, map_c) == 1)
	{
		free_mapdata_int(map_c, map->vertical);
		error_map(map->map_data, map->vertical, MAP_ERROR);
	}
	free_mapdata_int(map_c, map->vertical);
}
