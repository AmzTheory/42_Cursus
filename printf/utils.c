/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:03:31 by aalzubai          #+#    #+#             */
/*   Updated: 2023/01/17 09:26:20 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_str(char *str)
{
	int	c;


	c = 0;
	if (!str)
		return (-1);
	while (*(str) != '\0')
	{
		// ft_putchar_fd(*(str), 1);
		if (write(1, str, 1) == -1)
			return (-1);
		str++;
		c++;
	}
	return (c);
}

int	write_suffix(char *suf)
{
	int	count;

	count = put_str(suf);
	free(suf);
	return (count);
}

size_t	safe_strlen(char *str)
{
	if (!str)
		return (0);
	return (ft_strlen(str));
}

char	*getpre(t_config *con, size_t cur_len)
{
	size_t	i;
	char	pad;
	char	*str;
	size_t	rem_len;

	pad = ' ';
	if (con->zero && !con->dash && !con->prec)
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

char	*getpre_pr(t_config *con, size_t cur_len)
{
	size_t	i;
	char	pad;
	char	*str;
	size_t		rem_len;

	pad = '0';
	rem_len = con->precw - cur_len;
	if (rem_len > 0)
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

char	*getsuf(t_config *con, size_t cur_len)
{
	size_t	i;
	char	pad;
	char	*str;
	size_t	rem_len;

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
