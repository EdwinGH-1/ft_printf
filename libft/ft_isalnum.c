/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:09:48 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/04 20:14:38 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	return (0);
}

/*
#include <stdio.h>
int main(void)
{
    char *a[] = {"1", "9", "a", "b", "A", "Z", "-", "+"};
    int i = 0;

    while (i < 8)
    {
        printf("%s is alphanumeric? %d\n", a[i], ft_isalnum(a[i][0]));
        i++;
    }
    return (0);
}
*/
