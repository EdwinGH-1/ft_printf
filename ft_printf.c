/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:45:32 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/24 16:38:29 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_init_flag(void)
{
	t_flags	flag;

	flag.left = false;
	flag.zero = false;
	flag.precision = -1;
	flag.star = false;
	flag.hash = false;
	flag.space = false;
	flag.plus = false;
	flag.width = 0;
	return (flag);
}

int	ft_flag_precision(const char *str, int i, t_flags *flag, va_list args)
{
	i = i + 1;
	if (str[i] == '*')
	{
		flag->precision = va_arg(args, int);
		return (i + 1);
	}
	flag->precision = 0;
	while (ft_isdigit(str[i]))
	{
		flag->precision = (flag->precision * 10) + (str[i] - '0');
		i++;
	}
	return (i);
}

t_flags	ft_flag_width(t_flags flag, va_list args)
{
	flag.star = true;
	flag.width = va_arg(args, int);
	if (flag.width < 0)
	{
		flag.left = true;
		flag.width = flag.width * (-1);
	}
	return (flag);
}

t_flags	ft_flag_left(t_flags flag)
{
	flag.left = true;
	flag.zero = false;
	return (flag);
}

t_flags	ft_flag_digit(char c, t_flags flag)
{
	if (flag.star)
		flag.width = 0;
	flag.width = (flag.width * 10) + (c - '0');
	return (flag);
}

int	ft_parse_flags(const char *str, int i, t_flags *flag, va_list args)
{
	i = i + 1;
	while (str[i] != '\0' && ft_is_in(str[i], FLAGS))
	{
		if (str[i] == '#')
			flag->hash = true;
		if (str[i] == ' ')
			flag->space = true;
		if (str[i] == '+')
			flag->plus = true;
		if (str[i] == '.')
			i = ft_flag_precision(str, i, flag, args);
		if (str[i] == '*')
			*flag = ft_flag_width(*flag, args);
		if (str[i] == '-')
			*flag = ft_flag_left(*flag);
		if (str[i] == '0' && !(flag->left) && flag->width == 0)
			flag->zero = true;
		if (ft_isdigit(str[i]))
			*flag = ft_flag_digit(str[i], *flag);
		i++;
	}
	return (i);
}

int	ft_parse_specs(char c, va_list args, t_flags flag)
{
	int	count;

	count = 0;
	if (c == '%')
		count += ft_print_c('%', flag);
	if (c == 'c')
		count += ft_print_c(va_arg(args, char), flag);
	if (c == 's')
		count += ft_print_s(va_arg(args, char *), flag);
	if (c == 'p')
		count += ft_print_p((unsigned long)va_arg(args, void *), flag);
	if (c == 'd' || c == 'i')
		count += ft_print_d(va_arg(args, int), flag);
	if (c == 'u')
		count += ft_print_u(va_arg(args, unsigned int), flag);
	if (c == 'x')
		count += ft_print_x(va_arg(args, unsigned int), flag);
	if (c == 'X')
		count += ft_print_x_cap(va_arg(args, unsigned int), flag);
	return (count);
}

int	ft_parse_str(const char *str, va_list args)
{
	int		i;
	int		words;
	t_flags	flag;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		flag = ft_init_flag();
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			if (ft_is_in(str[i], FLAGS) == true)
				i = ft_parse_flags(str, i, &flag, args);
			else if (ft_is_in(str[i], SPECIFIERS) == true)
				words += ft_parse_specs(str[i], args, flag);
			else
				words += ft_print_word(str[i]);
		}
		else
			words += ft_print_word(str[i]);
		i++;
	}
	return (words);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*str;
	int		chars_written;

	if (!format || !format == '\0')
		return (0);
	str = ft_strdup(format);
	if (!str || *str == '\0')
		return (0);
	chars_written = 0;
	va_start(args, format);
	chars_written = ft_parse_str(str, args);
	va_end(args);
	free(str);
	return (chars_written);
}
