/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:34:52 by aalzubai          #+#    #+#             */
/*   Updated: 2023/01/17 14:11:02 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*getsign(t_config *con, int val)
{
	if (val < 0)
		return (ft_strdup("-"));
	if (con->plus && val >= 0)
		return (ft_strdup("+"));
	if (con->space && val >= 0)
		return (ft_strdup(" "));
	return (ft_strdup(""));
}

static int	write_output(char *pre, char *pre_c, char *s, char *val)
{
	int	count;

	if (ft_strlen(pre) > 0 && *(pre) == ' ')
	{
		count = put_str(pre);
		ft_putstr_fd(s, 1);
	}
	else
	{
		ft_putstr_fd(s, 1);
		count = put_str(pre);
	}
	count += ft_strlen(s);
	count += put_str(pre_c);
	if (*val == '-')
		count += put_str(val + 1);
	else
		count += put_str(val);
	free(s);
	free(pre);
	free(pre_c);
	free(val);
	return (count);
}

int	handle_int(va_list	ap, t_config *con)
{
	char	*s;
	int		val;
	char	*valstr;
	int		cur_len;
	char	*pre_r;

	val = va_arg(ap, int);
	s = getsign(con, val);
	valstr = ft_itoa(val);
	cur_len = ft_strlen(valstr);
	if (val < 0)
		cur_len -= 1;
	pre_r = getpre_pr(con, cur_len);
	cur_len += ft_strlen(pre_r) + ft_strlen(s);
	if (val == 0 && con->prec && !con->precw)
	{
		free(valstr);
		valstr = ft_strdup("");
		cur_len = 0;
	}
	return (write_output(getpre(con, cur_len), pre_r,
			s, valstr) + write_suffix(getsuf(con, cur_len)));
}
