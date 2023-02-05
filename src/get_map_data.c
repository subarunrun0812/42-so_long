/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subarunrun <subarunrun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:23:15 by subarunrun        #+#    #+#             */
/*   Updated: 2023/02/04 16:40:26 by subarunrun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	non_specific_character(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != 'C'
			&& str[i] != 'E' && str[i] != 'P' && str[i] != 'N')
			return (1);
		i++;
	}
	return (0);
}

char	*check_n(char *str)
{
	int		i;
	char	*res;

	if (ft_strchr(str, '\n'))
		return (str);
	res = (char *)malloc(sizeof(char) * ft_strlen(str) + 2);
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		res[i] = str[i];
		i++;
	}
	res[i++] = '\n';
	res[i] = '\0';
	free(str);
	return (res);
}

char	**ft_stradd(char **array, char *new)
{
	char	**res;
	int		i;
	int		len;

	len = 0;
	while (array && array[len] != NULL)
		len++;
	res = (char **)malloc(sizeof(char *) * (len + 2));
	if (!res)
		error_map(array, len, MALLOC_ERROR);
	i = 0;
	while (i < len)
	{
		res[i] = array[i];
		i++;
	}
	new = check_n(new);
	if (!new)
	{
		free_mapdata(array, len);
		error(MAP_ERROR);
	}
	res[i++] = new;
	res[i] = NULL;
	free(array);
	return (res);
}

void	get_map_size(t_map *map)
{
	int	i;
	int	base_len;
	int	len;
	int flag;
	
	i = 0;
	len = 0;
	flag = 0;
	base_len = ft_strlen(map->map_data[i]);
	while (map->map_data[i])
	{
		len = ft_strlen(map->map_data[i]);
		if (base_len != len)
			flag = 1;
		base_len = len;
		i++;
	}
	map->width = len - 1;
	map->vertical = i;
	if (flag > 0)
		error_map(map->map_data, map->vertical, MAP_ERROR);
}

void	get_map_data(int fd, t_map *map)
{
	char	*str;
	int		error_f;

	str = get_next_line(fd);
	if (!str)
		error(MAP_ERROR);
    //TODO:変更した。リークすエラーを解消
	error_f = 0;
	while (str)
	{
		// printf("str = %s\n",str);
		if (error_f == 1 || str[0] == '\n')
		{
			// free(str);
			error_f = 1;
		}
		else
		{
			if (non_specific_character(str) == 1)
				error_f = 1;
			map->map_data = ft_stradd(map->map_data, str);
		}
		str = get_next_line(fd);
	}
	if (error_f == 1)
	{
		free_mapdata(map->map_data, map->vertical);
		error(MAP_ERROR);
	}
	get_map_size(map);
	// free_mapdata(map->map_data, map->vertical);
	// exit(1);
}
