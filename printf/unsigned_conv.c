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

static int	write_output(char *pre, char *pre_r, char *suf, char *val)
{
	int	count;

	count = put_str(pre);
	count += put_str(pre_r);
	count += put_str(val);
	count += put_str(suf);
	free(pre);
	free(pre_r);
	free(val);
	free(suf);
	return (count);
}

int	handle_unsignedint(va_list	ap, t_config *con)
{
	char				*pre_r;
	unsigned int		val;
	char				*valstr;
	int					cur_len;

	val = va_arg(ap, unsigned int);
	valstr = ft_uitoa(val);
	cur_len = ft_strlen(valstr);
	pre_r = getpre_pr(con, cur_len);
	cur_len += ft_strlen(pre_r);
	if (val == 0 && con->prec && !con->precw)
	{
		free(valstr);
		valstr = ft_strdup("");
		cur_len = 0;
	}
	return (write_output(getpre(con, cur_len), pre_r,
			getsuf(con, cur_len), valstr));
}
