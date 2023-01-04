/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:54:27 by aalzubai          #+#    #+#             */
/*   Updated: 2022/12/13 19:51:54 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	get_number_of_digits(int nb)
{
	int		i;

	i = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static	void	ft_store_digits(int nb, char *str, int len)
{
	int		j;
	int		r;

	r = 0;
	j = len -1;
	while (nb != 0)
	{
		r = nb % 10;
		str[j] = '0' + r;
		j--;
		nb = nb / 10;
	}
	str[len] = '\0';
}

char	*ft_itoa(int n)
{
	int		n_digits;
	int		neg;
	char	*number;

	n_digits = get_number_of_digits(n);
	neg = 0;
	if (n == 0)
		return (ft_strdup("0"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		neg = 1;
		n *= -1;
	}
	number = malloc((sizeof(char)) * (n_digits + (neg) + 1));
	if (!number)
		return (NULL);
	if (neg)
		*number = '-';
	ft_store_digits(n, number, n_digits + (neg));
	return (number);
}
