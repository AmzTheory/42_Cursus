/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:58:09 by aalzubai          #+#    #+#             */
/*   Updated: 2022/10/05 18:58:09 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	check_remove(char c, char const *set, int set_length)
{
	int	i;

	i = 0;
	while (i < set_length)
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static	char	*assign_str(const char	*org, int e, int s)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * (e - s + 2));
	if (!str)
		return (NULL);
	while (i <= (e - s))
	{
		str[i] = org[s + (i)];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		s;
	int		e;
	int		set_len;

	if (!s1)
		return (NULL);
	s = 0;
	e = ft_strlen(s1) - 1;
	set_len = ft_strlen(set);
	while (s <= e)
	{
		if (! check_remove(s1[s], set, set_len))
			break ;
		s++;
	}
	while (e > s)
	{
		if (! check_remove(s1[e], set, set_len))
			break ;
		e--;
	}
	return (assign_str(s1, e, s));
}
