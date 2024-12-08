/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:31:46 by jthiew            #+#    #+#             */
/*   Updated: 2024/12/08 12:41:42 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_adr(unsigned long p)
{
	if (p >= 16)
	{
		ft_print_adr(p / 16);
		ft_print_adr(p % 16);
	}
	else
	{
		if (p < 16)
			ft_print_char(p + '0');
		else if (p >= 10)
			ft_print_char((p - 10) + 'a');
	}
}

int	ft_print_ptr(unsigned long p)
{
	int	count;

	count = 0;
	if (p == 0)
	{
		count += ft_print_str("(nil)");
		return (count);
	}
	count += ft_print_str("0x");
	ft_print_adr(p);
	count += ft_ptr_len(p);
	return (count);
}

int	ft_print_p(unsigned long p, t_flags flags)
{
	int	count;

	count = 0;
	if (p == 0)
		flags.width -= 4;
	else
		flags.width -= 2;
	if (flags.left == 1)
		count += ft_print_ptr(p);
	count += ft_pad_width(flags.width, ft_ptr_len(p), 0);
	if (flags.left == 0)
		count += ft_print_ptr(p);
	return (count);
}
