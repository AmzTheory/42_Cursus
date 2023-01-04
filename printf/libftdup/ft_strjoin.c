/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:08:11 by aalzubai          #+#    #+#             */
/*   Updated: 2022/10/05 18:08:11 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*str;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (len1 + len2 +1));
	if (!str)
		return (NULL);
	ret = str;
	while (*(s1) != '\0')
	{
		*str = *s1++;
		str++;
	}
	while (*(s2) != '\0')
	{
		*str = *s2++;
		str++;
	}
	*str = '\0';
	return (ret);
}
