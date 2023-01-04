/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:49:12 by aalzubai          #+#    #+#             */
/*   Updated: 2022/10/02 13:49:12 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	lastdigit(int stop, const char *str)
{
	int	i;

	i = stop;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i - 1);
}

static	int	move_spaces(const char *str, int i)
{
	while (1)
	{
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v'
			|| str[i] == '\t' || str[i] == '\b' || str[i] == '\f')
			i++;
		else
		{
			if (ft_isdigit(str[i]) || str[i] == '+' || str[i] == '-')
				return (i);
			else
				return (-1);
		}
	}
	return (i);
}

static int	return_atoi(const char *str, int stop, int sign)
{
	int		j;
	int		res;
	int		r;

	j = lastdigit(stop, str);
	res = get_int(str, stop, j);
	r = sign * res;
	return (r);
}	

int	ft_atoi(const char *str)
{
	int	stop;
	int	sign;

	stop = move_spaces(str, 0);
	if (stop == -1)
		return (0);
	sign = 1;
	if (str[stop] == '-')
	{
		sign = -1;
		str++;
	}
	else if (str[stop] == '+')
		str++;
	if (check_max(str, sign))
	{
		if (sign == 1)
			return (-1);
		return (0);
	}
	return (return_atoi(str, stop, sign));
}
