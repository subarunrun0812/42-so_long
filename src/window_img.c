/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subarunrun <subarunrun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:06:54 by subarunrun        #+#    #+#             */
/*   Updated: 2023/01/30 22:56:05 by subarunrun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_image(t_mlx *mlx, t_img *img)
{
	t_data	floor_data;

	floor_data.adr = (unsigned int *)mlx_get_data_addr(img->f_img,
			&floor_data.bpp, &floor_data.size_line, &floor_data.endian);
	img->f_img = create_img(mlx, &floor_data, "./src/xpm/grass.xpm");
	img->w_img = create_img(mlx, &floor_data, "./src/xpm/stone.xpm");
	img->c_img = create_img(mlx, &floor_data, "./src/xpm/gun.xpm");
	img->e_close_img = create_img(mlx, &floor_data, "./src/xpm/door.xpm");
	img->e_open_img = create_img(mlx, &floor_data, "./src/xpm/door_open.xpm");
	img->p_left_img = create_img(mlx, &floor_data,
			"./src/xpm/Pochita_left.xpm");
	img->p_right_img = create_img(mlx, &floor_data,
			"./src/xpm/Pochita_right.xpm");
	img->n_img = create_img(mlx, &floor_data, "./src/xpm/gun_devil.xpm");
}

void	window_image_init(t_mlx *mlx, t_img *img, t_map *map)
{
	int	tmp_width;
	int	tmp_vertical;

	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		error(MLX_ERROR);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, map->width * SIZE,
			map->vertical * SIZE, "so_long");
	if (!mlx->win_ptr)
		error(MLX_ERROR);
	img->f_img = mlx_xpm_file_to_image(mlx->mlx_ptr, "./src/xpm/grass.xpm",
			&tmp_width, &tmp_vertical);
	if (!img->f_img)
		error(MLX_ERROR);
	init_image(mlx, img);
}
