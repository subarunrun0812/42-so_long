/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_type.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susasaki <susasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:40:08 by susasaki          #+#    #+#             */
/*   Updated: 2022/10/25 17:32:24 by susasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUT_TYPE_H
# define FT_PUT_TYPE_H

# include <stdint.h>
# include <stdlib.h>

size_t	ft_put_char(int c);
size_t	ft_put_string(char *s);
size_t	ft_put_point(uintptr_t point);
size_t	ft_put_int(int num);
size_t	ft_put_uint(unsigned int num);
size_t	ft_put_hexlower(unsigned int n);
size_t	ft_put_hexupper(unsigned int n);

#endif