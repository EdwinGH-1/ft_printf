/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:34:28 by jthiew            #+#    #+#             */
/*   Updated: 2024/12/08 18:08:52 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef SPECS
#  define SPECS "cspdiuxX%"
# endif

# ifndef FLAGS
#  define FLAGS "-0.*# +"
# endif

typedef struct s_flags
{
	int	left;
	int	zero;
	int	precision;
	int	star;
	int	hash;
	int	space;
	int	plus;
	int	width;
	int	spec;
}	t_flags;

// printf
int		ft_parse_flags(const char *str, int i, va_list args, t_flags *flags);
int		ft_parse_specs(char c, va_list args, t_flags flags);
int		ft_parse_str(const char *str, va_list args);
int		ft_printf(const char *format, ...);

// printf_utils
int		ft_is_in(char c, char *set);
int		ft_is_flag(char c);

// print_c
int		ft_print_char(char c);
int		ft_print_c(char c, t_flags flag);

// print_s
int		ft_print_s_pre(char *s, int precision);
int		ft_print_string(char *s, t_flags flags);
int		ft_print_s(char *s, t_flags flag);
int		ft_print_str(char *s);

// print_d
int		ft_print_i(char *nbr_str, int d, t_flags flags);
int		ft_print_sign_pre(int d, t_flags *flags);
int		ft_print_integer(char *nbr_str, int d, t_flags flags);
int		ft_print_d(int d, t_flags flags);

// print_p
int		ft_print_p(unsigned long p, t_flags flags);
int		ft_print_ptr(unsigned long p);
void	ft_print_adr(unsigned long p);

// print_x
int		ft_print_x_prefix(int is_upper);
int		ft_print_hexad(char *nbr_str, int n, int is_upper, t_flags flags);
int		ft_print_hex(char *nbr_str, int n, int is_upper, t_flags flags);
int		ft_print_x(unsigned int n, int is_upper, t_flags flags);

// print_u
int		ft_print_un(char *nbr_str, t_flags flags);
int		ft_print_unsign(char *nbr_str, t_flags flags);
int		ft_print_u(unsigned int n, t_flags flags);

// flags_utils_1
t_flags	ft_init_flags(void);
t_flags	ft_flag_digit(char c, t_flags flags);
t_flags	ft_flag_width(t_flags flags, va_list args);
t_flags	ft_flag_left(t_flags flags);
int		ft_flag_precision(const char *str, int i, va_list args, t_flags *flags);

// flags_utils_2
int		ft_pad_width(int width, int len, int zero);

// printf_itoa
char	*ft_printf_itoa(long num);

// printf_xtoa
char	*ft_printf_xtoa(unsigned long num, int is_upper);

// printf_utoa
char	*ft_u_to_str(unsigned int num, char *str, size_t len);
char	*ft_printf_utoa(unsigned int num);

// nbr_len
int		ft_ptr_len(unsigned long n);
size_t	ft_xtoa_len(long n);
size_t	ft_utoa_len(long n);

#endif
