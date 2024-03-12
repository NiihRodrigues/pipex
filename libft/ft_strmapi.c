/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicrodri <nicrodri@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:06:14 by nicrodri          #+#    #+#             */
/*   Updated: 2023/11/15 13:51:43 by nicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	a;
	char			*substr;

	if (!s || !f)
		return (NULL);
	substr = (char *) malloc(ft_strlen(s) + 1);
	if (!substr)
		return (NULL);
	a = 0;
	while (s[a])
	{
		substr[a] = f(a, s[a]);
		a++;
	}
	substr[a] = '\0';
	return (substr);
}
/*
#include <stdio.h>

char test_func(unsigned int i, char str)
{
	printf("Testando minha funcao: index = %d & %c\n", i, str);
	if (str == '.')
		return (str);
	return (str - 32);
	}
int	main(void)
{
	char str[9] = "Nicole";
	printf("O resultado e %s\n", str);
	char *resultado = ft_strmapi(str, test_func);
	printf("O resultado é %s\n", resultado);
	return (0);
}*/
