/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:50:12 by aalzubai          #+#    #+#             */
/*   Updated: 2023/01/17 14:10:50 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void put_str_wrapper(char *str, int *count)
{
	int	c;

	if (*count != -1)
	{
		c = put_str(str);
		if (c == -1)
			*count = -1;
		else
			*count += c;
	}
	free(str);
}
#include <stdio.h>
static int	write_output(char *pre, char *pre_r, char *suf, char *val)
{
	int	count;

	count = 0;
	put_str_wrapper(pre, &count);
	put_str_wrapper(pre_r, &count);
	put_str_wrapper(val, &count);
	put_str_wrapper(suf, &count);
	return (count);
}

int	handle_unsignedint(va_list	ap, t_config *con)
{
	char				*pre_r;
	unsigned int		val;
	char				*valstr;
	size_t				cur_len;

	val = va_arg(ap, unsigned int);
	valstr = ft_uitoa(val);
	cur_len = safe_strlen(valstr);
	pre_r = getpre_pr(con, cur_len);
	cur_len = cur_len + safe_strlen(pre_r);
	if (!valstr || !pre_r)
		return (-1);
	if (val == 0 && con->prec && !con->precw)
	{
		free(valstr);
		valstr = ft_strdup("");
		cur_len = 0;
	}
	return (write_output(getpre(con, cur_len), pre_r,
			getsuf(con, cur_len), valstr));
}
