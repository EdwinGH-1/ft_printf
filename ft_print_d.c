/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:24:08 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/25 21:19:02 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_d(int d, t_flags flag)
{
	int		count;
	int		len;
	char	*digit_str;
	
	count = 0;
	len = 0;
	if (flag.left)
	{
		if (d >= 0 && (flag.plus || flag.space))
		{
			if (flag.plus)
			{
				count += ft_print_word('+');
				flag.space = false;
			}
			if (flag.space)
				count += ft_print_word(' ');
			len++;
		}
		digit_str = ft_itoa(d);
		count += ft_print_str(digit_str, ft_strlen(digit_str));
		len += ft_strlen(digit_str);
		if (d < 0)
		{
			if (flag.precision > ft_strlen(digit_str) - 1)
			{

			}
		}
			
		ft_pad_width(flag.width, len, false);

	if (flag.space)

	if (flag.zero)


}
