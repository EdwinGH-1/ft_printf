/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:17:05 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/24 16:17:49 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pad_width(int width, int len, bool zero)
{
	int	count;

	count = 0;
	while (width > len)
	{
		if (zero)
			count += ft_print_word('0');
		if (!zero)
			count += ft_print_word(' ');
		width--;
	}
	return (count);
}
