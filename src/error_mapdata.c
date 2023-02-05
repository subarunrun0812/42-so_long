/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mapdata.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subarunrun <subarunrun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:16:25 by subarunrun        #+#    #+#             */
/*   Updated: 2023/02/05 18:16:32 by subarunrun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_mapdata_int(int **map_data, int vertical)
{
	int	i;

	i = 0;
	if (vertical < 1)
		return ;
	while (i < vertical)
	{
		free(map_data[i]);
		i++;
	}
	free(map_data);
}

void	free_mapdata(char **map_data, int vertical)
{
	int	i;

	i = 0;
	if (vertical < 1)
		return ;
	while (i < vertical)
	{
		free(map_data[i]);
		i++;
	}
	free(map_data);
}

void	error_map(char **mapdata, int vertical, int error_num)
{
	free_mapdata(mapdata, vertical);
	error(error_num);
}
