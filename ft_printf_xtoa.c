/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xtoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:16:14 by jthiew            #+#    #+#             */
/*   Updated: 2024/12/08 17:22:02 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_hex_to_str(unsigned long num, char *str, size_t len)
{
	int	mod;

	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	len--;
	while (len != (size_t)-1)
	{
		mod = num % 16;
		if (mod < 10)
			str[len] = mod + '0';
		else if (mod >= 10)
			str[len] = (mod - 10) + 'a';
		num = num / 16;
		len--;
	}
	return (str);
}

char	*ft_printf_xtoa(unsigned long num, int is_upper)
{
	size_t	len;
	char	*str;
	int		i;

	len = ft_xtoa_len(num);
	str = 0;
	str = ft_hex_to_str(num, str, len);
	if (!str)
		return (NULL);
	if (is_upper == 1)
	{
		i = 0;
		while (str[i] != '\0')
		{
			if (str[i] >= 'a' && str[i] <= 'f')
				str[i] -= 32;
			i++;
		}
	}
	return (str);
}
