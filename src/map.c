/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subarunrun <subarunrun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:31:23 by subarunrun        #+#    #+#             */
/*   Updated: 2023/02/04 16:42:30 by subarunrun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	filename_check(char *filename)
{
	char	*ber;
	int		i;
	int		len;

	len = ft_strlen(filename);
	ber = ".ber";
	//TODO: i = ft_strlken(ber)
	i = ft_strlen(ber);
	//strncmpを使った方が分かりやすいかも
	while (ber[i--] == filename[len--])
	{
		if (i == 0)
			break ;
	}
	//TODO: ber[i] != filename[len]
	if (ber[i] != filename[len])
		error(FILENAME_ERROR);
	return ;
}

t_map	ft_map(char *filename)
{
	int		fd;
	t_map	map;

	map.map_data = NULL;
	filename_check(filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error(FILENAME_ERROR);
	get_map_data(fd, &map);
	check_map(&map);
	return (map);
}
