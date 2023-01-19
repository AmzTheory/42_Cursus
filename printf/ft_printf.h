/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:23:20 by aalzubai          #+#    #+#             */
/*   Updated: 2023/01/17 14:09:14 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
#include <stdio.h>

enum e_type
{
	char_type,
	str_type,
	ptr_type,
	d_type,
	i_type,
	u_type,
	lowerhex_type,
	upperhex_type,
	perce_type,
	unkown_type
};

typedef struct s_config
{
	int			zero;
	int			dash;
	int			hash;
	int			space;
	int			plus;
	int			prec;
	int			precw;
	int			wid;
	enum e_type	data_type;
}	t_config;

char			*ft_uitoa(unsigned int n);
char			*ft_dec_to_hex(unsigned long long int val, char start_char);
int				ft_printf(const char *str, ...);
t_config		*create_config(void);
int				read_config(t_config *config, const char *str);
int				handle_int(va_list	ap, t_config *con);
int				handle_string(va_list	ap, t_config *con);
int				handle_char(va_list	ap, t_config *con);
int				handle_unsignedint(va_list	ap, t_config *con);
int				put_str(char *str);
char			*getpre(t_config *con, size_t cur_len);
char			*getpre_pr(t_config *con, size_t cur_len);
char			*getsuf(t_config *con, size_t cur_len);
int				handle_hex(va_list	ap, t_config *con, char start_char);
int				handle_ptr(va_list	ap, t_config *con);
int				write_suffix(char *suf);
int				check_simple_flags(const char *str, t_config *config);
const char		*check_complex_flags(const char *str, t_config *config, int *i);
size_t			safe_strlen(char *str);
#endif
