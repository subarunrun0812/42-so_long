/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subarunrun <subarunrun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:17:00 by subarunrun        #+#    #+#             */
/*   Updated: 2023/02/04 16:52:18 by subarunrun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	search_player(t_map *map, t_pos *pos)
{
	pos->y = 1;
	while (pos->y < map->vertical)
	{
		pos->x = 1;
		while (pos->x < map->width)
		{
			if (map->map_data[pos->y][pos->x] == 'P')
				return ;
			pos->x++;
		}
		pos->y++;
	}
}

void	dstnation_set(int move, t_pos *dst, t_anim *anim)
{
	dst->x = 0;
	dst->y = 0;
	if (move == W_KEY)
		dst->y = -1;
	if (move == S_KEY)
		dst->y = 1;
	if (move == A_KEY)
	{
		dst->x = -1;
		anim->p_dir = 0;
	}
	if (move == D_KEY)
	{
		dst->x = 1;
		anim->p_dir = 1;
	}
}

void	arrival_img(t_param *param, t_pos *dst, t_pos *pos)
{
	pos->y = pos->y + dst->y;
	pos->x = pos->x + dst->x;
	param->map->map_data[pos->y - dst->y][pos->x - dst->x] = '0';
	if (param->map->map_data[pos->y][pos->x] == 'C')
	{
		param->map->map_data[pos->y][pos->x] = 'P';
		param->c_count++;
	}
	else if (param->map->map_data[pos->y][pos->x] == '0')
		param->map->map_data[pos->y][pos->x] = 'P';
	else if (param->map->map_data[pos->y][pos->x] == 'E')
	{
		param->e_flag = 1;
		param->map->map_data[pos->y][pos->x] = 'P';
		return ;
	}
	if (param->e_flag == 1)
	{
		param->map->map_data[pos->y - dst->y][pos->x - dst->x] = 'E';
		param->e_flag = 0;
	}
}

void	player_move(int move, t_param *param)
{
	t_pos	pos;
	t_pos	dst;

	search_player(param->map, &pos);
	dstnation_set(move, &dst, param->anim);
	if (param->map->map_data[pos.y + dst.y][pos.x + dst.x] == '1')
		return ;
	if (param->map->map_data[pos.y + dst.y][pos.x + dst.x] == 'E')
	{
		if (param->c_count == param->c_num)
			close_window(param);
	}
	if (param->map->map_data[pos.y + dst.y][pos.x + dst.x] == 'N')
		close_window(param);
	arrival_img(param, &dst, &pos);
	if (param->c_count == param->c_num)
		param->anim->door_f = 1;
	draw_map(param->map, param->mlx, param->img, param->anim);
	player_steps(param);
}
