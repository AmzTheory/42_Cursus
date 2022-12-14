/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:03:31 by aalzubai          #+#    #+#             */
/*   Updated: 2023/01/10 16:53:32 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char	*getpre(t_config *con, int cur_len)
{
	int		i;
	char	pad;
	char	*str;
	int		rem_len;

	pad = ' ';
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
	else
		str = ft_strdup("");
	return (str);
}

char	*getsuf(t_config *con, int cur_len)
{
	int		i;
	char	pad;
	char	*str;
	int		rem_len;

	pad = ' ';
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
	else
		str = ft_strdup("");
	return (str);
}
