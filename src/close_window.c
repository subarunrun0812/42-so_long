/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subarunrun <subarunrun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:34:36 by susasaki          #+#    #+#             */
/*   Updated: 2023/02/05 18:15:31 by subarunrun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_image(t_mlx *mlx, t_img *img)
{
	mlx_destroy_image(mlx->mlx_ptr, img->f_img);
	mlx_destroy_image(mlx->mlx_ptr, img->w_img);
	mlx_destroy_image(mlx->mlx_ptr, img->c_img);
	mlx_destroy_image(mlx->mlx_ptr, img->e_close_img);
	mlx_destroy_image(mlx->mlx_ptr, img->e_open_img);
	mlx_destroy_image(mlx->mlx_ptr, img->p_left_img);
	mlx_destroy_image(mlx->mlx_ptr, img->p_right_img);
	mlx_destroy_image(mlx->mlx_ptr, img->n_img);
}

void	close_window(t_param *param)
{
	destroy_image(param->mlx, param->img);
	free_mapdata(param->map->map_data, param->map->vertical);
	mlx_destroy_window(param->mlx->mlx_ptr, param->mlx->win_ptr);
	mlx_destroy_display(param->mlx->mlx_ptr);
	free(param->mlx->mlx_ptr);
	exit(0);
}
