// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   conversion.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/12/13 18:18:31 by aalzubai          #+#    #+#             */
// /*   Updated: 2023/01/09 15:31:24 by aalzubai         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "ft_printf.h"

// // pre+S+val+suf

// static char	*getsign(t_config *con, int val)
// {
// 	if (con->plus && val > 0)
// 		return (ft_strdup("+"));
// 	return (ft_strdup(""));
// }
// static int	write_output(char *pre, char *suf, char *s, char *val)
// {
// 	int	count;

// 	count = put_str(pre);
// 	count += put_str(s);
// 	count += put_str(val);
// 	count += put_str(suf);
// 	return count;
// }

// static int	write_str(char *pre, char *suf, char *val)
// {
// 	int	count;

// 	count = put_str(pre);
// 	count += put_str(val);
// 	count += put_str(suf);
// 	return count;
// }

// int	handle_int(va_list	ap, t_config *con)
// {
// 	char	*pre;
// 	char	*suf;
// 	char	*s;
// 	int		val;
// 	char	*valstr;
// 	int		cur_len;

// 	val = va_arg(ap, int);
// 	s = getsign(con, val);
// 	valstr = ft_itoa(val);
// 	cur_len = ft_strlen(valstr) + ft_strlen(s);
// 	pre = getpre(con, cur_len);
// 	suf = getsuf(con, cur_len);

// 	return write_output(pre, suf, s, valstr);
// }

// int	handle_string(va_list	ap, t_config *con)
// {
// 	char	*pre;
// 	char	*suf;
// 	char	*val;
// 	int		cur_len;

// 	val = va_arg(ap, char*);
// 	cur_len = ft_strlen(val);
// 	pre = getpre(con, cur_len);
// 	suf = getsuf(con, cur_len);

// 	return write_str(pre, suf, val);
// }
