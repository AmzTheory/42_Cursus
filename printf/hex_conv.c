/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:35:42 by aalzubai          #+#    #+#             */
/*   Updated: 2023/01/11 12:06:37 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*handle_ox(char *val, char *ox)
{
	char	*new_val;
	size_t 	i;

	if (!ox)
		return (val);
	new_val = malloc(ft_strlen(val) + 2 + 1);
	if (!new_val)
		return (NULL);
	new_val[0] =  ox[0];
	new_val[1] =  ox[1]; 
	i = 2;
	while (i < ft_strlen(val) + 2)
	{
		new_val[i] =  val[i - 2];
		i++;
	}
	new_val[i] = '\0';
	free(val);
	free(ox);
	return (new_val);
}

static int	write_output(char *pre, char *pre_r, char *suf, char *val)
{
	int		count;

	count = 0;
	if (ft_strlen(pre_r))
	count += put_str(pre);
	count += put_str(pre_r);
	count += put_str(val);
	count += put_str(suf);
	free(pre);
	free(pre_r);
	free(val);
	free(suf);
	return (count);
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
	valstr = handle_ox(valstr, ox);
	cur_len = ft_strlen(valstr);
	return (write_output(getpre(con, cur_len), pre_r,
			getsuf(con, cur_len), valstr));
}

int	handle_ptr(va_list	ap, t_config *con)
{
	void						*val;
	unsigned long long int		val_u;
	char						*valstr;
	int		         			cur_len;

	val = va_arg(ap, void *);
	val_u = (unsigned long long int) val;
	valstr = ft_dec_to_hex(val_u, 'a');
	valstr = handle_ox(valstr, ft_strdup("0x"));
	cur_len = ft_strlen(valstr);
	return  (write_output(getpre(con, cur_len), ft_strdup(""),
			getsuf(con, cur_len), valstr));
}
