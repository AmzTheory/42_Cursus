/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:03:31 by aalzubai          #+#    #+#             */
/*   Updated: 2023/01/04 16:57:18 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	put_str(char *str)
{
	int	c;

	c = 0;
	while (*(str) != '\0')
	{
		ft_putchar_fd(*(str), 1);
		c++;
		str++;
	}
	return (c);
}
