/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:32:40 by jthiew            #+#    #+#             */
/*   Updated: 2024/12/08 11:12:40 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pad_width(int width, int len, int zero)
{
	int	count;

	count = 0;
	while (width > len)
	{
		if (zero)
			count += ft_print_char('0');
		if (!zero)
			count += ft_print_char(' ');
		width--;
	}
	return (count);
}
