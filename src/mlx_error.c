/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subarunrun <subarunrun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:18:43 by subarunrun        #+#    #+#             */
/*   Updated: 2023/02/05 18:19:13 by subarunrun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_mlx_init(t_map *map)
{
	free_mapdata(map->map_data, map->vertical);
	error(MLX_ERROR);
}

void	error_win_init(t_mlx *mlx, t_map *map)
{
	free_mapdata(map->map_data, map->vertical);
	mlx_destroy_display(mlx->mlx_ptr);
	error(MLX_ERROR);
}

void	error_win_floor(t_mlx *mlx, t_map *map)
{
	free_mapdata(map->map_data, map->vertical);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	error(MLX_ERROR);
}
