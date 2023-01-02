/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:23:20 by aalzubai          #+#    #+#             */
/*   Updated: 2023/01/02 16:54:30 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

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
	dec_type,
	int_type,
	undec_type,
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

t_config	*create_config(void);
int			read_config(t_config *config, const char *str);
char		*getpre(t_config *con, int cur_len, int len);
#endif
