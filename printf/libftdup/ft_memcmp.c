/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:42:17 by aalzubai          #+#    #+#             */
/*   Updated: 2022/12/13 20:08:25 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int		i;
	char				*s1p;
	char				*s2p;
	unsigned char		a;
	unsigned char		b;

	s1p = (char *) s1;
	s2p = (char *) s2;
	i = 0;
	while (i < n)
	{
		a = (unsigned char) s1p[i];
		b = (unsigned char) s2p[i];
		if (a != b)
			return ((unsigned char) a - b);
		i++;
	}
	return (0);
}
