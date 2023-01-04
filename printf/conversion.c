/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:18:31 by aalzubai          #+#    #+#             */
/*   Updated: 2023/01/04 17:06:49 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

// pre+S+val+suf
static char	*getpre(t_config *con, int cur_len)
{
	int		i;
	char	pad;
	char	*str;
	int		rem_len;

	pad = ' ';
	str = ft_strdup("");
	if (con->zero && !con->dash)
		pad = '0';
	rem_len = con->wid - cur_len;
	if (con->dash == 0 && rem_len > 0)
	{
		str = malloc(rem_len + 1);
		if (!str)
			return (NULL);
		i = 0;
		while (i < rem_len)
		{
			str[i] = pad;
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
char static	*getsuf(t_config *con, int cur_len)
{
	int		i;
	char	pad;
	char	*str;
	int		rem_len;


	pad = ' ';
	str = ft_strdup("");
	if (con->zero && !con->dash)
		pad = '0';
	rem_len = con->wid - cur_len;
	if (con->dash && rem_len > 0)
	{
		str = malloc(rem_len + 1);
		if (!str)
			return (NULL);
		i = 0;
		while (i < rem_len)
		{
			str[i] = pad;
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
static char	*getsign(t_config *con, int val)
{
	if (con->plus && val > 0)
		return (ft_strdup("+"));
	return (ft_strdup(""));
}
int	write_output(char *pre, char *suf, char *s, char *val)
{
	int	count;

	count = put_str(pre);
	count += put_str(s);
	count += put_str(val);
	count += put_str(suf);
	return count;
}
int	handle_int(va_list	ap, t_config *con)
{
	char	*pre;
	char	*suf;
	char	*s;
	int		val;
	char	*valstr;
	int		cur_len;

	val = va_arg(ap, int);
	s = getsign(con, val);
	valstr = ft_itoa(val);
	cur_len = ft_strlen(valstr) + ft_strlen(s);
	pre = getpre(con, cur_len);
	suf = getsuf(con, cur_len);

	return write_output(pre, suf, s, valstr);
}
