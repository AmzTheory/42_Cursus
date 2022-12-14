/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:14:02 by aalzubai          #+#    #+#             */
/*   Updated: 2022/09/28 19:14:02 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int		i;
	char				*p;

	i = 0;
	p = (char *) s;
	while (i < n)
	{
		*p = '\0';
		p++;
		i++;
	}
}
