/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:14:03 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/24 17:48:34 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_word(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_print_c(char c, t_flags flag)
{
	int	count;

	count = 0;
	if (flag.left)
		count += ft_print_word(c);
	flag.zero = false;
	count += ft_pad_width(flag.width, 1, flag.zero);
	if (!flag.left)
		count += ft_print_word(c);
	return (count);
}
