/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susasaki <susasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:46:48 by susasaki          #+#    #+#             */
/*   Updated: 2022/10/27 02:26:24 by susasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_put_hexupper(unsigned int n)
{
	size_t	count;
	char	*str;

	if (n == 0)
		return (ft_put_char('0'));
	str = ft_toupper_all(ft_point_base(n, 16));
	count = ft_put_string(str);
	free(str);
	return (count);
}
