/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicrodri <nicrodri@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:58:30 by nicrodri          #+#    #+#             */
/*   Updated: 2023/11/14 17:58:47 by nicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_gstrlen(long n, int sign);

char	*ft_itoa(int n)
{
	char	*out;
	long	tmp;
	int		a;
	int		sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	tmp = (long) n * sign;
	a = ft_gstrlen(tmp, sign);
	out = malloc(a + 1);
	if (!out)
		return (0);
	out[a--] = '\0';
	while (tmp > 9)
	{
		out[a] = (char)(tmp % 10) + '0';
		tmp = tmp / 10;
		a--;
	}
	out[a] = (char)(tmp % 10) + '0';
	if (sign == -1)
		out[0] = '-';
	return (out);
}

static int	ft_gstrlen(long n, int sign)
{
	int	b;

	b = 1;
	while (n > 9)
	{
		n /= 10;
		b++;
	}
	if (sign == -1)
		b++;
	return (b);
}
/*
#include <stdio.h>

int	main(void)
{
	int a = 1;
	int b = 0;
	int c = 42;
	
	printf("Inteiro de 1 conv em string %s\n", ft_itoa(a));
	printf("Inteiro de 0 conv em string %s\n", ft_itoa(b));
	printf("Inteiro de 42 conv em string %s\n", ft_itoa(c));

	return (0);
}*/
