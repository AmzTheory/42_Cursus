/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:50:12 by aalzubai          #+#    #+#             */
/*   Updated: 2023/01/10 16:53:11 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_output(char *pre, char *suf, char *val)
{
	int	count;

	count = put_str(pre);
	count += put_str(val);
	count += put_str(suf);
	free(pre);
	free(val);
	free(suf);
	return (count);
}

int	handle_unsignedint(va_list	ap, t_config *con)
{
	char				*pre;
	char				*suf;
	unsigned int		val;
	char				*valstr;
	int					cur_len;

	val = va_arg(ap, unsigned int);
	valstr = ft_uitoa(val);
	cur_len = ft_strlen(valstr);
	pre = getpre(con, cur_len);
	suf = getsuf(con, cur_len);
	return (write_output(pre, suf, valstr));
}
