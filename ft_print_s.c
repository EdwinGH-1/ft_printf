/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:46:17 by jthiew            #+#    #+#             */
/*   Updated: 2024/12/08 18:09:43 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s_pre(char *s, int precision)
{
	int	count;

	count = 0;
	while (s[count] != '\0' && count < precision)
	{
		ft_putchar_fd(s[count], 1);
		count++;
	}
	return (count);
}

int	ft_print_string(char *s, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.precision >= 0)
	{
		count += ft_pad_width(flags.precision, ft_strlen(s), 0);
		count += ft_print_s_pre(s, flags.precision);
	}
	else
		count += ft_print_s_pre(s, ft_strlen(s));
	return (count);
}

int	ft_print_s(char *s, t_flags flags)
{
	int	count;

	count = 0;
	if (s == NULL && flags.precision > -1 && flags.precision < 6)
	{
		count += ft_pad_width(flags.width, 0, 0);
		return (count);
	}
	if (s == NULL)
		s = "(null)";
	if (flags.precision >= 0 && (size_t)flags.precision > ft_strlen(s))
		flags.precision = ft_strlen(s);
	if (flags.left == 1)
		count += ft_print_string(s, flags);
	if (flags.precision >= 0)
		count += ft_pad_width(flags.width, flags.precision, 0);
	else
		count += ft_pad_width(flags.width, ft_strlen(s), 0);
	if (flags.left == 0)
		count += ft_print_string(s, flags);
	return (count);
}

int	ft_print_str(char *s)
{
	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}
