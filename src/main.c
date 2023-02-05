/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subarunrun <subarunrun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:03:06 by subarunrun        #+#    #+#             */
/*   Updated: 2023/01/29 23:34:36 by subarunrun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;
	t_mlx	mlx;
	t_img	img;
	t_anim	anim;

	if (argc != 2)
		error(ARGS_ERROR);
	ft_map(argv[1], &map);
	draw(&map, &mlx, &img, &anim);
	ft_event(&mlx, &img, &map, &anim);
	exit(0);
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }