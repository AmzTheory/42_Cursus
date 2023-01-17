/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:34:15 by aalzubai          #+#    #+#             */
/*   Updated: 2023/01/17 11:24:14 by aalzubai         ###   ########.fr       */
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
	char	*number;

	n_digits = get_number_of_digits(n);
	if (n == 0)
		return (ft_strdup("0"));
	number = malloc((sizeof(char)) * (n_digits + 1));
	if (!number)
		return (NULL);
	ft_store_digits(n, number, n_digits);
	return (number);
}

static int	dec_to_hex_helper(unsigned long long int val)
{
	int	i;

	i = 0;
	while (val != 0)
	{
		val = val / 16;
		i++;
	}
	return (i);
}

char	*ft_dec_to_hex(unsigned long long int val, char start_char)
{
	int		hex_len;
	char	*str;
	int		j;
	int		rem;

	if (val == 0)
		return (ft_strdup("0"));
	hex_len = dec_to_hex_helper(val);
	str = malloc(hex_len + 1);
	if (!str)
		return (NULL);
	j = hex_len - 1;
	while (j >= 0)
	{
		rem = val % 16;
		if (rem < 10)
			str[j] = 48 + rem;
		else
			str[j] = (start_char - 10) + rem;
		val = val / 16;
		j--;
	}
	str[hex_len] = '\0';
	return (str);
}
