/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:06:35 by aalzubai          #+#    #+#             */
/*   Updated: 2022/12/14 17:31:17 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	getlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*(str) != '\0' && ft_isdigit(*(str)))
	{
		len += 1;
		str++;
	}
	return (len);
}

int	check_max(const char *str, int sign)
{
	size_t	len;
	char	*min;
	char	*max;

	max = "9223372036854775807";
	min = "9223372036854775808";
	len = getlen(str);
	if (len == 19)
	{
		if (sign == 1)
		{
			if (ft_strncmp(max, str, 19) == -1)
				return (-1);
		}
		else
		{
			if (ft_strncmp(min, str, 19) == -1)
				return (-1);
		}
	}
	else if (len > 19)
		return (-1);
	return (0);
}

static	int	power(int base, long expp)
{
	int	i;
	int	res;

	i = 0;
	res = 1;
	while (i < expp)
	{
		res *= base;
		i++;
	}
	return (res);
}

int	get_int(const char *str, int stop, int j)
{
	int		a;
	int		res;

	a = 0;
	res = 0;
	while (j >= stop)
	{
		res += (str[j] - '0') * (power((int)10, a));
		j--;
		a++;
	}
	return (res);
}	
