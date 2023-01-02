/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:57:37 by aalzubai          #+#    #+#             */
/*   Updated: 2022/12/13 20:02:34 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

static	int	check_edge_case(int *nb, int fd)
{
	char	*most_negative;

	if (*nb == 0)
	{
		ft_putchar('0', fd);
		return (1);
	}
	else if (*nb == -2147483648)
	{
		most_negative = "-2147483648";
		while (*most_negative != '\0')
		{
			ft_putchar(*most_negative, fd);
			most_negative++;
		}
		return (1);
	}
	else if (*nb < 0)
	{
		ft_putchar('-', fd);
		*nb = -*nb;
	}
	return (0);
}

static	int	ft_store_digits(int nb, int *arr)
{
	int		i;
	int		r;

	i = 0;
	r = 0;
	while (nb != 0)
	{
		r = nb % 10;
		arr[i] = r;
		i++;
		nb = nb / 10;
	}
	return (i - 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		zero;
	int		j;
	int		number[10];
	char	digit;

	zero = check_edge_case(&n, fd);
	if (zero)
		return ;
	j = ft_store_digits(n, number);
	while (j >= 0)
	{
		digit = '0' + number[j--];
		ft_putchar(digit, fd);
	}
}
