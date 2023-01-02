/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:58:36 by aalzubai          #+#    #+#             */
/*   Updated: 2022/12/14 10:15:53 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	char			*p;
	char			ci;

	i = 0;
	p = (char *) s;
	ci = c;
	while (i < n)
	{
		if (*p == ci)
			return (p);
		p++;
		i++;
	}
	return (0);
}
