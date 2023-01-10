/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:40:05 by aalzubai          #+#    #+#             */
/*   Updated: 2023/01/10 15:55:58 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*skipdigits(const char *str, int *i)
{
	while (ft_isdigit(*(str)))
	{
		str++;
		*i = *i + 1;
	}
	*i = *i - 1;
	return (str - 1);
}

static int	get_int_val(const char *c)
{
	int		ret;

	ret = ft_atoi(c);
	return (ret);
}

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
	config->data_type = i_type;
	return (config);
}
// %[-|0|#|+| ].dl

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
	return (unkown_type);
}

int	read_config(t_config *config, const char *str)
{
	int	i;

	i = 0;
	while (!ft_isalpha(*(str)))
	{
		if (*(str) == '0')
			config->zero = 1;
		else if (*(str) == '#')
			config->hash = 1;
		else if (*(str) == '-')
			config->dash = 1;
		else if (*(str) == ' ')
			config->space = 1;
		else if (*(str) == '+')
			config->plus = 1;
		else if (ft_isdigit(*(str)))
		{
			config->wid = get_int_val(str);
			str = skipdigits(str, &i);
		}
		else if (*(str) == '.')
		{
			str++;
			i++;
			if (ft_isdigit(*(str)))
			{
				config->prec = get_int_val(str);
				str = skipdigits(str, &i);
			}
			else
				str--;
		}
		i++;
		str++;
	}
	config->data_type = read_type((*str));
	return (i + 1);
}
