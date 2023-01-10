/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:34:52 by aalzubai          #+#    #+#             */
/*   Updated: 2023/01/10 16:50:42 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*getsign(t_config *con, int val)
{
	if (con->plus && val >= 0)
		return (ft_strdup("+"));
	if (con->space && val >= 0)
		return (ft_strdup(" "));
	return (ft_strdup(""));
}

static int	write_output(char *pre, char *suf, char *s, char *val)
{
	int	count;

	count = put_str(s);
	count += put_str(pre);
	count += put_str(val);
	count += put_str(suf);
	free(s);
	free(pre);
	free(val);
	free(suf);
	return (count);
}

int	handle_int(va_list	ap, t_config *con)
{
	char	*s;
	int		val;
	char	*valstr;
	int		cur_len;

	val = va_arg(ap, int);
	s = getsign(con, val);
	valstr = ft_itoa(val);
	cur_len = ft_strlen(valstr) + ft_strlen(s);
	return (write_output(getpre(con, cur_len),
			getsuf(con, cur_len), s, valstr));
}
