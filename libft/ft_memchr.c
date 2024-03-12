/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicrodri <nicrodri@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:02:23 by nicrodri          #+#    #+#             */
/*   Updated: 2023/11/15 11:13:31 by nicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	int				i;

	s1 = (unsigned char *)s;
	i = 0;
	while (n--)
	{
		if (s1[i] == (unsigned char)c)
			return (&s1[i]);
		else
			i++;
	}
	return (0);
}
