/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:40:05 by aalzubai          #+#    #+#             */
/*   Updated: 2023/01/17 12:05:12 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_config	*create_config(void)
{
	t_config	*config;

	config = malloc(sizeof(t_config));
	if (config == NULL)
		return (NULL);
	config->zero = 0;
	config->hash = 0;
	config->dash = 0;
	config->space = 0;
	config->plus = 0;
	config->prec = 0;
	config->wid = 0;
	config->precw = 0;
	config->data_type = i_type;
	return (config);
}

int	read_type(const char c)
{
	if (c == 'c')
		return (char_type);
	else if (c == 's')
		return (str_type);
	else if (c == 'p')
		return (ptr_type);
	else if (c == 'd')
		return (d_type);
	else if (c == 'i')
		return (i_type);
	else if (c == 'u')
		return (u_type);
	else if (c == 'x')
		return (lowerhex_type);
	else if (c == 'X')
		return (upperhex_type);
	else if (c == '%')
		return (perce_type);
	return (unkown_type);
}

int	read_config(t_config *config, const char *str)
{
	int	i;

	i = 1;
	str = str + 1;
	while (!ft_isalpha(*(str)) && *(str) != '%')
	{
		if (!check_simple_flags(str, config))
			str = check_complex_flags(str, config, &i);
		i++;
		str++;
	}
	config->data_type = read_type((*str));
	return (i + 1);
}
