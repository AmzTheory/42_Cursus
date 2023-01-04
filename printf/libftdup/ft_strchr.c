/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:09:55 by aalzubai          #+#    #+#             */
/*   Updated: 2022/12/13 20:02:26 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ci;

	ci = (char) c;
	while (*s != '\0')
	{
		if (ci == *s)
			return ((char *)s);
		s++;
	}
	if (ci == '\0')
	{
		return ((char *)s);
	}
	return (0);
}
