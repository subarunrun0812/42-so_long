/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subarunrun <subarunrun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:49:40 by subarunrun        #+#    #+#             */
/*   Updated: 2023/01/30 22:54:27 by subarunrun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdio.h>

typedef struct s_anim
{
	int	p_dir;
	int	door_f;
}			t_anim;

typedef struct s_img
{
	void	*f_img;
	void	*w_img;
	void	*c_img;
	void	*e_close_img;
	void	*e_open_img;
	void	*p_left_img;
	void	*p_right_img;
	void	*n_img;
}			t_img;

typedef struct s_map
{
	char	**map_data;
	int		vertical;
	int		width;
}			t_map;

typedef struct s_num
{
	int	c_num;
	int	e_num;
	int	p_num;
}			t_num;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_mlx;

typedef struct s_pos
{
	int	x;
	int	y;
}			t_pos;

typedef struct s_data
{
	unsigned int	*adr;
	void			*img;
	int				bpp;
	int				size_line;
	int				endian;
}			t_data;

typedef struct s_param
{
	t_map	*map;
	t_mlx	*mlx;
	t_img	*img;
	t_anim	*anim;
	int		res;
	int		steps;
	int		c_num;
	int		c_count;
	int		e_flag;
}			t_param;

#endif