/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_steps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subarunrun <subarunrun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:49:41 by subarunrun        #+#    #+#             */
/*   Updated: 2023/02/04 16:52:20 by subarunrun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_steps(t_param *param)
{
	char	*steps_c;

	steps_c = ft_itoa(param->steps++);
	if (!steps_c)
		return ;
	mlx_string_put(param->mlx->mlx_ptr, param->mlx->win_ptr,
		5, 11, 0xFFFFFF, steps_c);
	free(steps_c);
	ft_printf("steps = %d\n", param->steps);
}
