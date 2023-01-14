/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:36:22 by aalzubai          #+#    #+#             */
/*   Updated: 2023/01/14 11:46:30 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_str(char *pre, char *suf, char *val, int free_p)
{
	int	count;

	count = put_str(pre);
	count += put_str(val);
	count += put_str(suf);
	if (free_p)
		free(val);
	free(pre);
	free(suf);
	return (count);
}

static char	*reduce_str(char *val, int limit)
{
	char	*new_val;
	int		i;

	i = 0;
	new_val = malloc(limit + 1);
	if (!new_val)
		return (NULL);

	while (i < limit)
	{
		new_val[i] = val[i];
		i++;
	}

	new_val[i] = '\0';
	return (new_val);
}

int	handle_string(va_list	ap, t_config *con)
{
	char	*pre;
	char	*suf;
	char	*val;
	int		cur_len;
	int		free_p;

	free_p = 0;
	val = va_arg(ap, char *);
	if (val == NULL)
		val = "(null)";
	if (con->prec)
	{
		val = reduce_str(val, con->precw);
		free_p = 1;
	}
	cur_len = ft_strlen(val);
	pre = getpre(con, cur_len);
	suf = getsuf(con, cur_len);
	return (write_str(pre, suf, val, free_p));
}
