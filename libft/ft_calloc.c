/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicrodri <nicrodri@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:01:40 by nicrodri          #+#    #+#             */
/*   Updated: 2023/11/15 12:24:46 by nicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	mul;

	mul = (nmemb * size);
	if ((nmemb) && (mul) && ((mul / nmemb) != size))
		return ((char *) NULL);
	ptr = malloc(mul);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, mul);
	return (ptr);
}
