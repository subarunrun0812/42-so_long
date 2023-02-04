/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susasaki <susasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:18:46 by susasaki          #+#    #+#             */
/*   Updated: 2022/10/28 10:54:57 by susasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

size_t	ft_put_string(char *s)
{
	if (s == NULL)
		s = "(null)";
	write(1, s, ft_strlen(s));
	return ((size_t)ft_strlen(s));
}
