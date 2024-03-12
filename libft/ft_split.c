/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicrodri <nicrodri@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:03:24 by nicrodri          #+#    #+#             */
/*   Updated: 2023/11/15 13:50:16 by nicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnt_str(char const *s, char c);
static int	sp_wds(char **res, char const *s, char c, int wd);

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (cnt_str(s, c) + 1));
	if (!res)
		return (NULL);
	if (!sp_wds(res, s, c, 0))
		return (NULL);
	return (res);
}

static int	cnt_str(char const *s, char c)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (s[i] != 0)
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			nbr++;
		i++;
	}
	return (nbr);
}

static int	sp_wds(char **res, char const *s, char c, int wd)
{
	int		start;
	int		end;

	end = 0;
	start = 0;
	while (s[end])
	{
		if (s[end] == c || s[end] == 0)
			start = end + 1;
		if (s[end] != c && (s[end + 1] == c || s[end + 1] == 0))
		{
			res[wd] = malloc(sizeof(char) * (end - start + 2));
			if (!res[wd])
			{
				while (wd++)
					free(res[wd]);
				return (0);
			}
			ft_strlcpy(res[wd], (s + start), end - start + 2);
			wd++;
		}
		end++;
	}
	res[wd] = 0;
	return (1);
}
/*
#include <stdio.h>
int    main()
{
    char *string = "Nicole";
    char delimitador = 'c';
    char **dividido;
    int i;
    i = 0;

    printf("%s \n", string);
    dividido = ft_split(string, delimitador);

    printf("->%s", dividido[i]);

    return(0);
}*/
