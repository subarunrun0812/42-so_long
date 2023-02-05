/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subarunrun <subarunrun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:31:23 by subarunrun        #+#    #+#             */
/*   Updated: 2023/02/05 18:18:36 by subarunrun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	filename_check(char *filename)
{
	char	*ber;
	int		i;
	int		len;

	len = ft_strlen(filename);
	ber = ".ber";
	i = ft_strlen(ber);
	while (ber[i--] == filename[len--])
	{
		if (i == 0)
			break ;
	}
	if (ber[i] != filename[len])
		error(FILENAME_ERROR);
	return ;
}

static void	t_map_init(t_map *map)
{
	map->map_data = NULL;
	map->vertical = 0;
	map->width = 0;
}

void	ft_map(char *filename, t_map *map)
{
	int		fd;

	t_map_init(map);
	filename_check(filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error(FILENAME_ERROR);
	get_map_data(fd, map);
	check_map(map);
}
