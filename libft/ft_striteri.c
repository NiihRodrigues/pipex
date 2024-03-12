/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicrodri <nicrodri@strudent.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:10:10 by nicrodri          #+#    #+#             */
/*   Updated: 2023/11/15 13:52:49 by nicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	a;

	if (s && f)
	{
		a = 0;
		while (s[a])
		{
			f(a, &s[a]);
			a++;
		}
	}
}
/*
#include <stdio.h>
#include <unistd.h>

void prtchar(unsigned int n, char *str)
{
	int num = '0' + n;
	write(1, &(num), 1);
	write(1, str, 1);
}

int main(void)
{
	char str[10] = "Nicole";
	ft_striteri(str, prtchar);
	return (0);
}*/
