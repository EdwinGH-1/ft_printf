/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:34:28 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/24 19:23:33 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdbool.h>

# ifndef SPECIFIERS
#  define SPECIFIERS "cspdiuxX%"
# endif

# ifndef FLAGS
#  define FLAGS "-0.*# +"
# endif

typedef struct s_flags
{
	bool	left;
	bool	zero;
	int		precision;
	bool	star;
	bool	hash;
	bool	space;
	bool	plus;
	int		width;
}	t_flags;

// printf_utils
bool	ft_is_in(char c, char *set);

// print_c
int		ft_print_c(char c, t_flags flag);
int		ft_print_word(char c);

// print_s
int		ft_print_s_pre(char *s, t_flags flag);
int		ft_print_str(char *s, int len);
int		ft_print_s(char *s, t_flags flag);

// flags_utils
int		ft_pad_width(int width, int len, bool zero);

#endif
