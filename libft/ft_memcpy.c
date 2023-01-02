/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:46:38 by aalzubai          #+#    #+#             */
/*   Updated: 2022/09/28 17:46:38 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char				*p_dst;
	char				*p_src;
	unsigned int		i;

	if (!src && !dst)
		return (NULL);
	p_dst = (char *) dst;
	p_src = (char *) src;
	i = 0;
	while (i < n)
	{
		*p_dst = *p_src;
		p_dst++;
		p_src++;
		i++;
	}
	return (dst);
}
