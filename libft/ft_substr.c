/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:21:47 by nicrodri          #+#    #+#             */
/*   Updated: 2023/11/15 13:39:54 by nicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*i;
	size_t	nlen;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		i = ft_calloc(1, sizeof(char));
		if (!i)
			return (NULL);
	}
	else
	{
		nlen = ft_strlen(s + start);
		if (!(nlen < len))
			nlen = len;
		i = (char *)malloc((nlen + 1) * sizeof(char));
		if (!i)
			return (NULL);
		i[nlen] = 0;
		while (nlen-- > 0)
			i[nlen] = s[start + nlen];
	}
	return (i);
}
/*
#include <stdio.h>

int	main(void)
{
	char s[] = "teste para retirada de uma substring do indice 11 com 8 caract.";

    int start = 11;
    int len = 8;

    char* str = ft_substr(s, start, len);

    printf("%s\n\n", s);
    printf("Resultado = ");
    printf("%s\n", str);

    return (0);
}*/
