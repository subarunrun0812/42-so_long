/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susasaki <susasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:26:46 by susasaki          #+#    #+#             */
/*   Updated: 2022/10/28 10:54:27 by susasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*ft_change_base(unsigned long ori, size_t base, char *str, size_t size)
{
	str[size] = '\0';
	while (ori != 0)
	{
		if (ori % base < 10)
			str[size - 1] = (ori % base) + 48;
		else if (ori % base >= 10)
			str[size - 1] = (ori % base) + 55;
		ori /= base;
		size--;
	}
	return (str);
}

char	*ft_point_base(unsigned long point, size_t base)
{
	unsigned long	ori;
	size_t			size;
	char			*str;

	ori = point;
	if (ori == 0)
		return (ft_strdup("0"));
	size = 0;
	while (point)
	{
		point /= base;
		size++;
	}
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (0);
	str = ft_change_base(ori, base, str, size);
	return (str);
}
