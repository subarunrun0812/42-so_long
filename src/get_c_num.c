/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_c_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susasaki <susasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:20:50 by subarunrun        #+#    #+#             */
/*   Updated: 2023/01/11 09:54:25 by susasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_c_num(t_map *map)
{
	int	x;
	int	y;
	int	num_c;

	num_c = 0;
	y = 1;
	while (y < map->vertical)
	{
		x = 1;
		while (x < map->width)
		{
			if (map->map_data[y][x] == 'C')
				num_c++;
			x++;
		}
		y++;
	}
	return (num_c);
}
