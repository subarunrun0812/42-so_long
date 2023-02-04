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

void	*non_specific_character(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != 'C'
			&& str[i] != 'E' && str[i] != 'P' && str[i] != 'N')
			error(MAP_ERROR);
		i++;
	}
	return (NULL);
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
	size_t	i;
	size_t	len;

	len = 0;
	while (array && array[len] != NULL)
		len++;
	res = (char **)malloc(sizeof(char *) * (len + 2));
	if (!res)
		error(MALLOC_ERROR);
	i = 0;
	while (i < len)
	{
		res[i] = array[i];
		i++;
	}
	new = check_n(new);
	if (!new)
		error(MALLOC_ERROR);
	res[i] = new;
	i++;
	res[i] = NULL;
	free(array);
	return (res);
}

void	get_map_size(t_map *map)
{
	size_t	i;
	size_t	base_len;
	size_t	len;
	size_t	vertical;

	i = 0;
	len = 0;
	vertical = 0;
	base_len = ft_strlen(map->map_data[i]);
	while (map->map_data[vertical] != NULL)
		vertical++;
	while (map->map_data[i] != NULL && i < vertical)
	{
		len = ft_strlen(map->map_data[i]);
		if (base_len != len)
		{
			error(MAP_ERROR);
			free(map->map_data[i]);
		}
		base_len = len;
		i++;
	}
	map->width = len - 1;
	map->vertical = i;
}

void	get_map_data(int fd, t_map *map)
{
	char	*str;
	int		is_error;

	str = get_next_line(fd);
	if (!str)
		error(MAP_ERROR);
    //TODO:変更した。リークすエラーを解消
	is_error = 0;
	while (str)
	{
		if (is_error == 1 || str[0] == '\n')
		{
			free(str);
			is_error = 1;
		}
		else
		{
			non_specific_character(str);
			map->map_data = ft_stradd(map->map_data, str);
		}
		str = get_next_line(fd);
	}
	if (is_error == 1)
		error(MAP_ERROR);
	get_map_size(map);
}
