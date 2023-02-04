/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subarunrun <subarunrun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 00:24:38 by subarunrun        #+#    #+#             */
/*   Updated: 2023/01/31 12:37:02 by subarunrun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_one_anim_img(t_param *param, int y, int x)
{
	if (param->map->map_data[y][x] == 'E')
	{
		if (param->anim->door_f == 1)
			mlx_put_image_to_window(param->mlx->mlx_ptr, param->mlx->win_ptr,
				param->img->e_open_img, x * SIZE, y * SIZE);
		else
			mlx_put_image_to_window(param->mlx->mlx_ptr, param->mlx->win_ptr,
				param->img->e_close_img, x * SIZE, y * SIZE);
	}
	else if (param->map->map_data[y][x] == 'P')
	{
		if (param->anim->p_dir == 1)
			mlx_put_image_to_window(param->mlx->mlx_ptr, param->mlx->win_ptr,
				param->img->p_right_img, x * SIZE, y * SIZE);
		else if (param->anim->p_dir == 0)
			mlx_put_image_to_window(param->mlx->mlx_ptr, param->mlx->win_ptr,
				param->img->p_left_img, x * SIZE, y * SIZE);
	}
}

void	draw_one_img(t_param *param, int y, int x)
{
	if (param->map->map_data[y][x] == '0')
		mlx_put_image_to_window(param->mlx->mlx_ptr, param->mlx->win_ptr,
			param->img->f_img, x * SIZE, y * SIZE);
	else if (param->map->map_data[y][x] == '1')
		mlx_put_image_to_window(param->mlx->mlx_ptr, param->mlx->win_ptr,
			param->img->w_img, x * SIZE, y * SIZE);
	else if (param->map->map_data[y][x] == 'C')
		mlx_put_image_to_window(param->mlx->mlx_ptr, param->mlx->win_ptr,
			param->img->c_img, x * SIZE, y * SIZE);
	else if (param->map->map_data[y][x] == 'N')
		mlx_put_image_to_window(param->mlx->mlx_ptr, param->mlx->win_ptr,
			param->img->n_img, x * SIZE, y * SIZE);
	else if (param->map->map_data[y][x] == 'E')
		draw_one_anim_img(param, y, x);
	else if (param->map->map_data[y][x] == 'P')
		draw_one_anim_img(param, y, x);
}

void	draw_map(t_map *map, t_mlx *mlx, t_img *img, t_anim *anim)
{
	t_param	param;
	int		y;
	int		x;

	param.map = map;
	param.mlx = mlx;
	param.img = img;
	param.anim = anim;
	y = 0;
	while (y < map->vertical)
	{
		x = 0;
		while (x < map->width)
		{
			draw_one_img(&param, y, x);
			x++;
		}
		y++;
	}
}

void	draw(t_map *map, t_mlx *mlx, t_img *img)
{
	t_anim	anim;

	anim.p_dir = 0;
	window_image_init(mlx, img, map);
	draw_map(map, mlx, img, &anim);
}
