/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subarunrun <subarunrun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 07:32:00 by subarunrun        #+#    #+#             */
/*   Updated: 2023/01/31 12:37:48 by subarunrun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*compare_image_data(t_mlx *mlx, t_data *img_data, t_data *floor_data)
{
	void	*res;
	t_data	res_data;
	int		y;
	int		x;

	res = mlx_new_image(mlx->mlx_ptr, SIZE, SIZE);
	res_data.adr = (unsigned int *)mlx_get_data_addr(res, &res_data.bpp,
			&res_data.size_line, &res_data.endian);
	floor_data = floor_data;
	y = 0;
	while (y < SIZE)
	{
		x = 0;
		while (x < SIZE)
		{
			if (img_data->adr[(y * SIZE) + x] == 0xFF000000)
				res_data.adr[(y * SIZE) + x] = floor_data->adr[(y * SIZE) + x];
			else
				res_data.adr[(y * SIZE) + x] = img_data->adr[(y * SIZE) + x];
			x++;
		}
		y++;
	}
	return (res);
}

void	*create_img(t_mlx *mlx, t_data *floor_data, char *filename)
{
	void	*res;
	t_pos	pos;
	t_data	img_data;
	void	*img_ptr;

	pos.x = 0;
	pos.y = 0;
	img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, filename, &pos.x, &pos.y);
	if (!img_ptr)
		error(MLX_ERROR);
	img_data.adr = (unsigned int *)mlx_get_data_addr(img_ptr, &img_data.bpp,
			&img_data.size_line, &img_data.endian);
	if (!img_data.adr)
		error(MLX_ERROR);
	res = compare_image_data(mlx, &img_data, floor_data);
	mlx_destroy_image(mlx->mlx_ptr, img_ptr);
	return (res);
}
