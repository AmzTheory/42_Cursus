/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:01:00 by aalzubai          #+#    #+#             */
/*   Updated: 2022/12/13 20:02:10 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	get_limit(size_t dstsize, size_t len)
{
	size_t	limit;

	limit = dstsize - len - 1;
	if (dstsize <= len)
		limit = 0;
	return (limit);
}

static	size_t	return_strlcat(char *dst, size_t i, size_t dstsize, size_t len)
{
	if (dstsize && len < dstsize)
		*dst = '\0';
	if (dstsize <= len)
		return (i + dstsize);
	return (i + len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;
	size_t	limit;

	i = 0;
	len = 0;
	if (!dst && !dstsize)
		return (0);
	while (*dst != '\0' && len < dstsize)
	{
		len++;
		dst++;
	}
	limit = get_limit(dstsize, len);
	while (*src != '\0')
	{
		if (i < limit)
		{
			*dst = *src;
			dst++;
		}
		src++;
		i++;
	}
	return (return_strlcat(dst, i, dstsize, len));
}
