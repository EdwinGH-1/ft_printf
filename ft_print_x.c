/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:55:26 by jthiew            #+#    #+#             */
/*   Updated: 2024/12/08 17:11:32 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_x_prefix(int is_upper)
{
	if (is_upper == 1)
		return (ft_print_str("0X"));
	else
		return (ft_print_str("0x"));
}

int	ft_print_hexad(char *nbr_str, int n, int is_upper, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.zero == 0 && flags.hash == 1 && n != 0)
		count += ft_print_x_prefix(is_upper);
	if (flags.precision >= 0)
		count += ft_pad_width(flags.precision - 1, ft_strlen(nbr_str) - 1, 1);
	count += ft_print_str(nbr_str);
	return (count);
}

int	ft_print_hex(char *nbr_str, int n, int is_upper, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.zero == 1 && flags.hash == 1 && n != 0)
		count += ft_print_x_prefix(is_upper);
	if (flags.left == 1)
		count += ft_print_hexad(nbr_str, n, is_upper, flags);
	if (flags.precision >= 0 && (size_t)flags.precision < ft_strlen(nbr_str))
		flags.precision = ft_strlen(nbr_str);
	if (flags.precision >= 0)
	{
		flags.width -= flags.precision;
		count += ft_pad_width(flags.width, 0, 0);
	}
	else
		count += ft_pad_width(flags.width,
				ft_strlen(nbr_str) + (flags.hash * 2), flags.zero);
	if (flags.left == 0)
		count += ft_print_hexad(nbr_str, n, is_upper, flags);
	return (count);
}

int	ft_print_x(unsigned int n, int is_upper, t_flags flags)
{
	char	*nbr_str;
	int		count;

	count = 0;
	if (flags.precision == 0 && n == 0)
	{
		count += ft_pad_width(flags.width, 0, 0);
		return (count);
	}
	nbr_str = ft_printf_xtoa(n, is_upper);
	if (!nbr_str)
		return (0);
	count += ft_print_hex(nbr_str, n, is_upper, flags);
	free(nbr_str);
	return (count);
}
