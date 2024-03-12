/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicrodri <nicrodri@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:02:42 by nicrodri          #+#    #+#             */
/*   Updated: 2023/11/15 11:14:26 by nicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst1;
	unsigned char	*src1;

	i = 0;
	dst1 = (unsigned char *)dest;
	src1 = (unsigned char *)src;
	if (!dst1 && !src1)
		return (0);
	if (((size_t)dest) - ((size_t)src) < n)
	{
		i = (n - 1);
		while (i < n)
		{
			dst1[i] = src1[i];
			i--;
		}
	}
	while (i < n)
	{
		dst1[i] = src1[i];
		i++;
	}
	return (dst1);
}
