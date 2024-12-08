/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:28:42 by jthiew            #+#    #+#             */
/*   Updated: 2024/12/08 17:36:35 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_un(char *nbr_str, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.precision >= 0)
		count += ft_pad_width(flags.precision - 1, ft_strlen(nbr_str) - 1, 1);
	count += ft_print_str(nbr_str);
	return (count);
}

int	ft_print_unsign(char *nbr_str, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.left == 1)
		count += ft_print_un(nbr_str, flags);
	if (flags.precision >= 0 && (size_t)flags.precision < ft_strlen(nbr_str))
		flags.precision = ft_strlen(nbr_str);
	if (flags.precision >= 0)
	{
		flags.width -= flags.precision;
		count += ft_pad_width(flags.width, 0, 0);
	}
	else
		count += ft_pad_width(flags.width, ft_strlen(nbr_str), flags.zero);
	if (flags.left == 0)
		count += ft_print_un(nbr_str, flags);
	return (count);
}

int	ft_print_u(unsigned int n, t_flags flags)
{
	char	*nbr_str;
	int		count;

	count = 0;
	if (flags.precision == 0 && n == 0)
	{
		count += ft_pad_width(flags.width, 0, 0);
		return (count);
	}
	nbr_str = ft_printf_utoa(n);
	if (!nbr_str)
		return (0);
	count += ft_print_unsign(nbr_str, flags);
	free (nbr_str);
	return (count);
}
