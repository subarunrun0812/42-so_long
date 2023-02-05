/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subarunrun <subarunrun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:52:19 by marvin            #+#    #+#             */
/*   Updated: 2023/02/04 16:52:20 by subarunrun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <X11/keysymdef.h>
# include "../get_next_line/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include "../printf/header/ft_printf.h"
# include "../printf/libft/libft.h"
# include "struct.h"

# define ARGS_ERROR 0
# define FILENAME_ERROR 1
# define MAP_ERROR 2
# define MALLOC_ERROR 3
# define MLX_ERROR 4

# define SIZE 50

# define W_KEY 0x0077  
# define A_KEY 0x0061
# define S_KEY 0x0073
# define D_KEY 0x0064
# define ESC_KEY 0xff1b

# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_FOCUSLN 9
# define ON_DESTROY 17

// check_goal.c
int		**map_init(t_map *map);
void	player_spot(t_map *map, int *i, int *j);
void	goal_nav(t_map *map, int **map_c, int i, int j);
int		check_goal_nav(t_map *map, int **map_c);
void	check_goal(t_map *map);

// check_map.c
void	check_map(t_map *map);
void	check_map_char(t_map *map);
void	num_init(t_num *num);
void	check_map_wall(t_map *map);
void	check_map_upperlower(char *width, t_map *map);

//create_img.c
void	*create_img(t_mlx *mlx, t_data *data, char *filename);
void	*compare_image_data(t_mlx *mlx, t_data *tmp_data, t_data *floor_data);

//close_window.c
void	destroy_image(t_mlx *mlx, t_img *img);
void	close_window(t_param *param);

//draw.c
void	draw(t_map *map, t_mlx *mlx, t_img *img,t_anim *anim);
void	draw_map(t_map *map, t_mlx *mlx, t_img *img, t_anim *anim);
void	draw_one_img(t_param *param, int y, int x);
void	draw_one_anim_img(t_param *param, int y, int x);

//error_mapdata.c
void	free_mapdata_int(int **map_data,int vertical);
void	free_mapdata(char **map_data,int vertical);
void	error_map(char **mapdata, int vertical, int error_num);

//error.c
void	putstr_error(int error_num);
void	error(int error_num);
// void	error_handle(int error_num, ...);

//mlx_error.c
void	error_mlx_init(t_map *map);
void	error_win_init(t_mlx *mlx, t_map *map);
void	error_win_floor(t_mlx *mlx, t_map *map);

//event.c
int		key_hook(int keycode, t_param *param);
int		ft_key_hook(int keycode, t_param *param);
int		ft_expose_hook(t_param *param);
int		ft_destroy_hook(t_param *param);
void	ft_event(t_mlx *mlx, t_img *img, t_map *map, t_anim *anim);

//get_c_num.c
int		get_c_num(t_map *map);

//get_map_data.c
int		non_specific_character(char *str);
char	*check_n(char *str);
char	**ft_stradd(char **array, char *new);
void	get_map_size(t_map *map);
void	get_map_data(int fd, t_map *map);

//map.c
// void	map_init(t_map *map);
// void	filename_check(char *filename);
void	ft_map(char *filename,t_map *map);

// player_move.c
void	arrival_img(t_param *param, t_pos *dst, t_pos *pos);
void	search_player(t_map	*map, t_pos	*pos);
void	dstnation_set(int move, t_pos *dst, t_anim *anim);
void	player_move(int move, t_param *param);

// player_steps.c
void	player_steps(t_param *param);

//window_img.c
// int		num_make(t_img *img);
// void	image_check(t_mlx *mlx, t_img *img, t_map *map);
void	init_image(t_mlx *mlx, t_img *img);
void	window_image_init(t_mlx *mlx, t_img *img, t_map *map,t_anim *anim);

#endif