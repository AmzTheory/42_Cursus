/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 18:33:58 by aalzubai          #+#    #+#             */
/*   Updated: 2022/12/14 08:39:12 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	get_len(char const *s, unsigned int start, size_t len, size_t l)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = start;
	while (i < l && j < len && *s != '\0')
	{
			i++;
			s++;
			j++;
	}
	return (j);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*sub;
	unsigned int		i;
	char				*sptr;
	size_t				lens;

	if (!s)
		return (NULL);
	i = 0;
	lens = ft_strlen(s);
	if (start >= lens)
		return (ft_strdup("\0"));
	sptr = (char *) &s[start];
	sub = malloc(get_len(s, start, len, lens) + 1);
	if (sub == NULL)
		return (NULL);
	while (i < len && *sptr != '\0')
	{
		sub[i] = *sptr;
		sptr++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
