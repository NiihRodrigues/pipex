/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicrodri <nicrodri@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:04:11 by nicrodri          #+#    #+#             */
/*   Updated: 2023/11/15 13:40:22 by nicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	int		b;
	char	*str;

	if (!s1)
		return (NULL);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s1 || !s2 || !str)
		return (0);
	a = 0;
	while (s1[a] != '\0')
	{
		str[a] = s1[a];
		a++;
	}
	b = 0;
	while (s2[b] != '\0')
		str[a++] = s2[b++];
	str[a] = '\0';
	return (str);
}
/*
#include<stdio.h>

int	main(void)
{
	char s1[] = "Nicole ";
	char s2[] = "Rodrigues";
 
    char* str = ft_strjoin(s1, s2);

    printf("ft_strjoin de s1=Nicole e s2=Rodrigues \n\n");
    printf("O resultado é = "); 
    printf("%s\n", str);
 
    return (0);	
}*/
