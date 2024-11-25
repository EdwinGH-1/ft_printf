/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:46:17 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/24 17:48:13 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s_pre(char *s, t_flags flag)
{
	int	len;

	if (flag.precision > -1)
	{
		if (ft_strlen(s) > flag.precision)
			len = flag.precision;
		else
			len = ft_strlen(s);
	}
	if (flag.precision == -1)
		len = ft_strlen(s);
	return (len);
}

int	ft_print_str(char *s, int len)
{
	int	count;

	count = 0;
	while (len > 0)
	{
		count += ft_print_word(*s);
		s++;
		len--;
	}
	return (count);
}

int	ft_print_s(char *s, t_flags flag)
{
	int	count;
	int	len;

	count = 0;
	if (!s && flag.precision > -1 && flag.precision < 6)
	{
		count += ft_pad_width(flag.width, 0, false);
		return (count);
	}
	if (!s)
	{
		count += ft_pad_width(flag.width, 6, false);
		count += ft_print_str("(null)", 6);
		return (6);
	}
	len = ft_print_s_pre(s, flag);
	if (flag.left)
		count += ft_print_str(s, len);
	flag.zero = false;
	count += ft_pad_width(flag.width, len, flag.zero);
	if (!flag.left)
		count += ft_print_str(s, len);
	return (count);
}
