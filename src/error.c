/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subarunrun <subarunrun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:40:16 by subarunrun        #+#    #+#             */
/*   Updated: 2023/01/29 23:33:46 by subarunrun       ###   ########.fr       */
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



// void	error_handle(int error_num,void *adr)
// {
// 	printf("call error_handle\n");
// 	void	*tmp;

// 	putstr_error(error_num);
// 	while (1)
// 	{
// 		tmp = adr;
// 		if (!tmp)
// 			break;
// 		printf("free: tmp(%p)\n",tmp);
// 		free(tmp);
// 	}
// 	exit(1);
// }


/*
int main(void)
{
    int error_num = FILENAME_ERROR;
    char *str1;
    char *str2;

    str1 = (char *)malloc(sizeof(char) * 3);
    str2 = (char *)malloc(sizeof(char) * 4);
    error_handle(error_num, str1, str2, NULL);
    return (0);
}
*/