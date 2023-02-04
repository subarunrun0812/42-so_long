/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susasaki <susasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:18:20 by susasaki          #+#    #+#             */
/*   Updated: 2022/10/28 10:55:01 by susasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static unsigned long	ft_digit(unsigned long n)
{
	size_t	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static char	*ft_uitoa(unsigned int num)
{
	char			*str_num;
	unsigned long	n;
	size_t			len;

	n = num;
	if (n == 0)
		return (ft_strdup("0"));
	len = ft_digit(n);
	str_num = (char *)malloc(sizeof(char) * (len + 1));
	if (str_num == NULL)
		return (NULL);
	str_num[len] = '\0';
	len--;
	while (n > 0)
	{
		str_num[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (str_num);
}

size_t	ft_put_uint(unsigned int num)
{
	size_t	count;
	char	*str;

	str = ft_uitoa(num);
	count = ft_put_string(str);
	free(str);
	return (count);
}
