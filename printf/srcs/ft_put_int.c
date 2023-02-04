/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susasaki <susasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:04:33 by susasaki          #+#    #+#             */
/*   Updated: 2022/10/28 10:54:44 by susasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

size_t	ft_put_int(int num)
{
	size_t	count;
	char	*str;

	str = ft_itoa(num);
	count = ft_put_string(str);
	free(str);
	return (count);
}
