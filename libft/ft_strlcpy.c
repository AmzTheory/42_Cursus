/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:06:07 by aalzubai          #+#    #+#             */
/*   Updated: 2022/12/13 20:02:04 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	while (*src != '\0')
	{
		if (i + 1 < dstsize)
		{
			*dst = *src;
			dst++;
		}
		src++;
		i++;
	}
	if (dstsize)
		*dst = '\0';
	return (i);
}
