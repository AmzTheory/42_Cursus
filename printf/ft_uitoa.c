/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:34:15 by aalzubai          #+#    #+#             */
/*   Updated: 2023/01/10 16:52:17 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	get_number_of_digits(unsigned int nb)
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

static	void	ft_store_digits(unsigned int nb, char *str, int len)
{
	int					j;
	unsigned int		r;

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

char	*ft_uitoa(unsigned int n)
{
	int		n_digits;
	int		neg;
	char	*number;

	n_digits = get_number_of_digits(n);
	neg = 0;
	if (n == 0)
		return (ft_strdup("0"));
	number = malloc((sizeof(char)) * (n_digits + 1));
	if (!number)
		return (NULL);
	ft_store_digits(n, number, n_digits);
	return (number);
}
