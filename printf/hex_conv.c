/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:35:42 by aalzubai          #+#    #+#             */
/*   Updated: 2023/01/11 11:41:53 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	dec_to_hex_helper(unsigned int val)
{
	int	i;

	i = 0;
	while (val != 0)
	{
		val = val / 16;
		i++;
	}
	return (i);
}

char	*dec_to_hex(unsigned int val, char start_char)
{
	int		hex_len;
	char	*str;
	int		j;
	int		rem;

	if (val == 0)
		return (ft_strdup("0"));
	hex_len = dec_to_hex_helper(val);
	str = malloc(hex_len + 1);
	if (!str)
		return (NULL);
	j = hex_len - 1;
	while (j >= 0)
	{
		rem = val % 16;
		if (rem < 10)
			str[j] = 48 + rem;
		else
			str[j] = (start_char - 10) + rem;

		val = val / 16;
		j--;
	}
	str[hex_len] = '\0';
	return (str);
}

static int	write_output(char *pre, char *suf, char *val, int ox)
{
	int		count;
	char	*temp;

	count = 0;
	if (ox)
	{
		temp = strdup("0x");
		count += put_str(temp);
		free(temp);
	}
	count += put_str(pre);
	count += put_str(val);
	count += put_str(suf);
	free(pre);
	free(val);
	free(suf);
	return (count);
}

int	handle_hex(va_list	ap, t_config *con, char start_char)
{
	unsigned int		val;
	char				*valstr;
	int					cur_len;

	val = va_arg(ap, unsigned int);
	valstr = dec_to_hex(val, start_char);
	cur_len = ft_strlen(valstr);
	return (write_output(getpre(con, cur_len),
			getsuf(con, cur_len), valstr, 0));
}

int	handle_ptr(va_list	ap, t_config *con)
{
	void				*val;
	unsigned int		val_u;
	char				*valstr;
	int					cur_len;

	val = va_arg(ap, void *);
	val_u = (unsigned int) &val;
	valstr = dec_to_hex(val_u, 'a');
	cur_len = ft_strlen(valstr);
	return (write_output(getpre(con, cur_len),
			getsuf(con, cur_len), valstr,1));
}
