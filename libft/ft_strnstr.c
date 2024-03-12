/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicrodri <nicrodri@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:06:22 by nicrodri          #+#    #+#             */
/*   Updated: 2023/11/15 12:26:01 by nicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_little;

	if ((len == 0 && !*little) || !*little)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	len_little = ft_strlen(little);
	while (*big != '\0' && len_little <= len)
	{
		if (!(ft_memcmp(big, little, len_little)))
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
