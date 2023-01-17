/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:35:42 by aalzubai          #+#    #+#             */
/*   Updated: 2023/01/17 15:48:00 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_output(char *pre, char *pre_r, char *ox, char *val)
{
	int		count;

	count = 0;
	count += put_str(pre);
	if (ox)
		count += put_str(ox);
	count += put_str(pre_r);
	count += put_str(val);
	free(pre);
	free(pre_r);
	free(ox);
	free(val);
	return (count);
}

static void	get_cur_len(int *cur_len, char *pre_r, char	*ox)
{
	if (ox)
		*cur_len += ft_strlen(pre_r) + ft_strlen(ox);
	else
		*cur_len += ft_strlen(pre_r);
}

int	handle_hex(va_list	ap, t_config *con, char start_char)
{
	unsigned int				val;
	char						*valstr;
	int							cur_len;
	char						*ox;
	char						*pre_r;

	ox = NULL;
	val = va_arg(ap, unsigned int);
	if (con->hash && val != 0 && con->data_type == upperhex_type)
		ox = ft_strdup("0X");
	else if (con->hash && val != 0 && con->data_type == lowerhex_type)
		ox = ft_strdup("0x");
	valstr = ft_dec_to_hex(val, start_char);
	cur_len = ft_strlen(valstr);
	pre_r = getpre_pr(con, cur_len);
	get_cur_len(&cur_len, pre_r, ox);
	if (val == 0 && con->prec && !con->precw)
	{
		free(valstr);
		valstr = ft_strdup("");
		ox = NULL;
		cur_len = 0;
	}
	return (write_output(getpre(con, cur_len), pre_r,
			ox, valstr) + write_suffix(getsuf(con, cur_len)));
}

int	handle_ptr(va_list	ap, t_config *con)
{
	void						*val;
	unsigned long long int		val_u;
	char						*valstr;
	int							cur_len;

	val = va_arg(ap, void *);
	val_u = (unsigned long long int) val;
	valstr = ft_dec_to_hex(val_u, 'a');
	cur_len = ft_strlen(valstr) + 2;
	return (write_output(getpre(con, cur_len), ft_strdup(""),
			ft_strdup("0x"), valstr) + write_suffix(getsuf(con, cur_len)));
}
