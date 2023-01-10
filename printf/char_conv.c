/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:39:12 by aalzubai          #+#    #+#             */
/*   Updated: 2023/01/10 16:51:17 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_char(char *pre, char *suf, char val)
{
	int	count;

	count = put_str(pre);
	ft_putchar_fd(val, 1);
	count += 1;
	count += put_str(suf);
	free(pre);
	free(suf);
	return (count);
}

int	handle_char(va_list	ap, t_config *con)
{
	char	*pre;
	char	*suf;
	char	val;

	val = va_arg(ap, int);
	pre = getpre(con, 1);
	suf = getsuf(con, 1);
	return (write_char(pre, suf, val));
}
