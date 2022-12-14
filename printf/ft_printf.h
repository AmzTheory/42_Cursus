/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:23:20 by aalzubai          #+#    #+#             */
/*   Updated: 2023/01/10 16:54:32 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include "libft/libft.h"
# include <stdarg.h>

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
	int			wid;
	enum e_type	data_type;
}	t_config;

char		*ft_uitoa(unsigned int n);
int			ft_printf(const char *str, ...);
t_config	*create_config(void);
int			read_config(t_config *config, const char *str);
int			handle_int(va_list	ap, t_config *con);
int			handle_string(va_list	ap, t_config *con);
int			handle_char(va_list	ap, t_config *con);
int			handle_unsignedint(va_list	ap, t_config *con);
int			put_str(char *str);
char		*getpre(t_config *con, int cur_len);
char		*getsuf(t_config *con, int cur_len);
#endif
