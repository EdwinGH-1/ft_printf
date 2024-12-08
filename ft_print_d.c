/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:49:31 by jthiew            #+#    #+#             */
/*   Updated: 2024/12/08 12:29:47 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_i(char *nbr_str, int d, t_flags flags)
{
	int	count;

	count = 0;
	if (d < 0)
	{
		if (flags.zero == 0 || flags.precision >= 0)
			count += ft_print_char('-');
	}
	else if (flags.plus == 1 && flags.zero == 0)
		count += ft_print_char('+');
	else if (flags.space == 1 && flags.zero == 0)
		count += ft_print_char(' ');
	if (flags.precision >= 0)
		count += ft_pad_width(flags.precision - 1, ft_strlen(nbr_str) - 1, 1);
	count += ft_print_str(nbr_str);
	return (count);
}

int	ft_print_sign_pre(int d, t_flags *flags)
{
	int	count;

	count = 0;
	if (d < 0 && flags->precision == -1)
	{
		count += ft_print_char('-');
		flags->width--;
	}
	else if (flags->plus == 1)
		count += ft_print_char('+');
	else if (flags->space == 1)
	{
		count += ft_print_char(' ');
		flags->width--;
	}
	return (count);
}

int	ft_print_integer(char *nbr_str, int d, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.zero == 1)
		count += ft_print_sign_pre(d, &flags);
	if (flags.left)
		count += ft_print_i(nbr_str, d, flags);
	if (flags.precision >= 0 && (size_t)flags.precision < ft_strlen(nbr_str))
		flags.precision = ft_strlen(nbr_str);
	if (flags.precision >= 0)
	{
		flags.width -= flags.precision;
		if (d < 0 && flags.left == 0)
			flags.width -= 1;
		count += ft_pad_width(flags.width, 0, 0);
	}
	else
		count += ft_pad_width(flags.width - flags.plus - flags.space,
				ft_strlen(nbr_str), flags.zero);
	if (flags.left == 0)
		count += ft_print_i(nbr_str, d, flags);
	return (count);
}

int	ft_print_d(int d, t_flags flags)
{
	long	nbr;
	int		count;
	char	*nbr_str;

	nbr = d;
	count = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		if (flags.zero == 0)
			flags.width--;
	}
	if (flags.precision == 0 && d == 0)
	{
		count += ft_pad_width(flags.width, 0, 0);
		return (count);
	}
	nbr_str = ft_itoa(nbr);
	if (!nbr_str)
		return (0);
	count += ft_print_integer(nbr_str, d, flags);
	free(nbr_str);
	return (count);
}
