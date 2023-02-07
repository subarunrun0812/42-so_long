/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subarunrun <subarunrun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:40:16 by subarunrun        #+#    #+#             */
/*   Updated: 2023/02/07 19:36:21 by subarunrun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	putstr_error(int error_num)
{
	if (error_num == ARGS_ERROR)
		ft_putstr_fd("error: argument\n", STDERR_FILENO);
	if (error_num == FILENAME_ERROR)
		ft_putstr_fd("error: file name\n", STDERR_FILENO);
	if (error_num == MAP_ERROR)
		ft_putstr_fd("error: map\n", STDERR_FILENO);
	if (error_num == MALLOC_ERROR)
		ft_putstr_fd("error: malloc\n", STDERR_FILENO);
	if (error_num == MLX_ERROR)
		ft_putstr_fd("error: minilibx\n", STDERR_FILENO);
}

void	error(int error_num)
{
	putstr_error(error_num);
	exit(1);
}
