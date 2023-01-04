/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:55:39 by aalzubai          #+#    #+#             */
/*   Updated: 2022/12/13 21:26:54 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*loop(const char *hay, const char *ne, size_t len, size_t c)
{
	char			*found;
	unsigned int	i;

	found = 0;
	i = 0;
	while (*hay != '\0' && i++ < len)
	{
		if (*hay == ne[c])
		{
			if (c == 0)
				found = (char *) hay;
			if (++c == ft_strlen(ne))
				return (found);
		}
		else if (c)
		{
			i = i - c;
			hay = hay - c + 1;
			c = 0;
			continue ;
		}
		hay++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			cur_id;

	if (!haystack && !len)
		return (0);
	if (*needle == '\0')
		return ((char *) haystack);
	if (ft_strlen(haystack) < len)
		len = ft_strlen(haystack);
	cur_id = 0;
	return (loop(haystack, needle, len, cur_id));
}
