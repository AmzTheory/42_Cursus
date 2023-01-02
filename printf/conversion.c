/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:18:31 by aalzubai          #+#    #+#             */
/*   Updated: 2023/01/02 16:57:31 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

// pre+S+val+suf
char	*getpre(t_config *con, int cur_len, int len)
{
	int		i;
	char	pad;
	char	*str;

	pad = ' ';
	str = ft_strdup("");
	if (con->zero && !con->dash)
		pad = '0';
	if (con->dash == 0)
	{
		str = malloc(len - cur_len + 1);
		if (!str)
			return (NULL);
		i = 0;
		while (i < (len - cur_len))
		{
			*(str) = pad;
			str++;
			i++;
		}
		*(str) = '\0';
	}
	return (str);
}
// // static char	*getsuf(t_config *con, int len)
// // {

// // }
// static	char	*getsign(t_config *con, int val)
// {
// 	char	c;

// 	c = '';
// 	if (con->plus && val > 0)
// 		c = '+';
// 	return (c);
// }
// int	handle_int(va_list	ap, t_config *con)
// {
// 	int	val;
// 	int	count;
// 	char	pad;
// 	count = 0;
// 	val = va_arg(ap, int);
// 	pad = ' ';
// 	if (con->zero)
// 		pad = '0';

// }

