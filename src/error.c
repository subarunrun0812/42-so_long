/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subarunrun <subarunrun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:40:16 by subarunrun        #+#    #+#             */
/*   Updated: 2023/02/05 18:16:36 by subarunrun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	putstr_error(int error_num)
{
	if (error_num == ARGS_ERROR)
		ft_putstr_fd("error: argument\n", STDERR_FILENO);
	if (error_num == FILENAME_ERROR)
		ft_putstr_fd("error: file name\n", FILENAME_ERROR);
	if (error_num == MAP_ERROR)
		ft_putstr_fd("error: map\n", MAP_ERROR);
	if (error_num == MALLOC_ERROR)
		ft_putstr_fd("error: malloc\n", MALLOC_ERROR);
	if (error_num == MLX_ERROR)
		ft_putstr_fd("error: minilibx\n", MLX_ERROR);
}

void	error(int error_num)
{
	putstr_error(error_num);
	exit(1);
}
