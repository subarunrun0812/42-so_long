/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susasaki <susasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 12:37:41 by susasaki          #+#    #+#             */
/*   Updated: 2022/10/30 15:30:25 by susasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_separate_date_types(char c, va_list *args)
{
	size_t	count;

	count = 0;
	if (c == 'c')
		count = ft_put_char(va_arg(*args, int));
	else if (c == 's')
		count = ft_put_string(va_arg(*args, char *));
	else if (c == 'p')
		count = ft_put_point((uintptr_t)va_arg(*args, void *));
	else if (c == 'd' || c == 'i')
		count = ft_put_int(va_arg(*args, int));
	else if (c == 'u')
		count = ft_put_uint(va_arg(*args, unsigned int));
	else if (c == 'x')
		count = ft_put_hexlower(va_arg(*args, unsigned int));
	else if (c == 'X')
		count = ft_put_hexupper(va_arg(*args, unsigned int));
	else if (c == '%')
		count = ft_put_char('%');
	return (count);
}

int	ft_count_output(char *save, va_list *args)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (save[i] != '\0')
	{
		if (save[i] == '%')
		{
			i++;
			count += ft_separate_date_types(save[i], args);
		}
		else
		{
			ft_putchar_fd(save[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	char	*save;
	va_list	args;
	size_t	count;

	save = ft_strdup(format);
	if (!save)
		return (0);
	count = 0;
	va_start(args, format);
	count = ft_count_output(save, &args);
	va_end(args);
	free(save);
	return (count);
}
