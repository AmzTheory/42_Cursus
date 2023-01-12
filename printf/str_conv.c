/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:36:22 by aalzubai          #+#    #+#             */
/*   Updated: 2023/01/12 14:37:42 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_str(char *pre, char *suf, char *val)
{
	int	count;

	count = put_str(pre);
	count += put_str(val);
	count += put_str(suf);
	free(pre);
	free(suf);
	return (count);
}

static int	write_str_perc(char *val, int limit)
{
	int	count;

	count = put_str_limit(val, limit);
	return (count);
}

int	handle_string(va_list	ap, t_config *con)
{
	char	*pre;
	char	*suf;
	char	*val;
	int		cur_len;

	val = va_arg(ap, char *);
	if (val == NULL)
	{
		val = "(null)";
		cur_len = 6;
	}
	else
		cur_len = ft_strlen(val);
	if (con->prec)
		return (write_str_perc(val, con->precw));
	pre = getpre(con, cur_len);
	suf = getsuf(con, cur_len);
	return (write_str(pre, suf, val));
}
