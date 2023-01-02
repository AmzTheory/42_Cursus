/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:25:50 by aalzubai          #+#    #+#             */
/*   Updated: 2022/12/13 20:07:00 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	forward(char *dst, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}

static	void	backward(char *dst, char *src, size_t n)
{
	int	i;

	i = n - 1;
	while (i >= 0)
	{
		dst[i] = src[i];
		i--;
	}
}

static	int	check_overlap(char *dst, char *src, size_t n)
{
	int	l;

	l = dst - src;
	if (l < 0)
		l = l * -1;
	return ((size_t)l < n);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*pdst;
	char	*psrc;

	if (!src && !dst)
		return (NULL);
	pdst = (char *) dst;
	psrc = (char *) src;
	if (psrc < pdst && check_overlap(pdst, psrc, n))
		backward(pdst, psrc, n);
	else if (psrc > pdst && check_overlap(pdst, psrc, n))
		forward(pdst, psrc, n);
	else
		forward(pdst, psrc, n);
	return (pdst);
}
