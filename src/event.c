/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susasaki <susasaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 23:45:08 by subarunrun        #+#    #+#             */
/*   Updated: 2023/06/21 15:16:09 by susasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_destroy_hook(t_param *param)
{
	close_window(param);
	return (0);
}

int	ft_resize_hook(t_param *param)
{
	draw_map(param->map, param->mlx, param->img, param->anim);
	return (0);
}

int	ft_key_hook(int keycode, t_param *param)
{
	if (keycode == W_KEY || keycode == S_KEY
		|| keycode == A_KEY || keycode == D_KEY)
		player_move(keycode, param);
	if (keycode == ESC_KEY)
		close_window(param);
	return (0);
}

void	ft_event(t_mlx *mlx, t_img *img, t_map *map, t_anim *anim)
{
	t_param	param;

	param.mlx = mlx;
	param.img = img;
	param.map = map;
	param.anim = anim;
	param.c_count = 0;
	param.c_num = get_c_num(map);
	param.steps = 0;
	param.e_flag = 0;
	param.res = 0;
	mlx_hook(mlx->win_ptr, ON_FOCUSLN, 1L << 21, &ft_resize_hook, &param);
	mlx_hook(mlx->win_ptr, ON_KEYDOWN, 1L << 0, &ft_key_hook, &param);
	mlx_hook(mlx->win_ptr, ON_DESTROY, 1L << 2, &ft_destroy_hook, &param);
	mlx_loop(mlx->mlx_ptr);
}
