/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susasaki <susasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:57:49 by susasaki          #+#    #+#             */
/*   Updated: 2022/10/27 02:36:30 by susasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_put_point(uintptr_t point)
{
	size_t	count;
	char	*str;

	str = ft_tolower_all(ft_point_base(point, 16));
	count = ft_put_string("0x");
	count += ft_put_string(str);
	free(str);
	return (count);
}

// int	main(void)
// {
// 	void	*str;

// 	str = 31;
// 	// 31 = 0x1f
// 	ft_put_point(str);
// 	return (0);
// }
