/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:49:31 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/27 19:49:33 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//count = return length
//len = length of print (for ft_pad_width)
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
    len += ft_strlen(digit_str);
    if (flag.precision == -1)
    {
      count += ft_pad_width(flag.width, len, flag.zero);
    }
    else 
    {
      if (
      count += ft_pad_width(flag.width - flag.precision, len, flag.zero);
    }

    

	// continue logic here
	}
}
		

if (d < 0)
			count += ft_print_word('-');
		if (d >= 0)
			num_digit = ft_strlen(digit_str);
		else
			num_digit = ft_strlen(digit_str) - 1;
		if (flag.precision == -1)
		{
			count += ft_pad_width(flag.width, num_digit, flag.zero);
			count += ft_print_str(digit_str, num_digit);
		}

		len += ft_strlen(digit_str);
		count += ft_print_str(digit_str, ft_strlen(digit_str));
			
		ft_pad_width(flag.width, len, false);

	if (flag.space)

	if (flag.zero)


}
