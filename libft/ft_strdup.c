/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 18:14:24 by aalzubai          #+#    #+#             */
/*   Updated: 2022/12/13 20:02:20 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t			length_of_s1;
	char			*ret;
	size_t			i;

	length_of_s1 = ft_strlen(((char *)s1));
	i = 0;
	ret = (char *) malloc(length_of_s1 + 1);
	if (!ret)
		return (NULL);
	while (i < (length_of_s1))
	{
		*ret = *(s1++);
		ret++;
		i++;
	}
	*ret = '\0';
	return (ret - i);
}
