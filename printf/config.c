/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:40:05 by aalzubai          #+#    #+#             */
/*   Updated: 2022/12/13 18:36:39 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	get_int(const char c)
{
	char	*st;
	int		ret;

	st = malloc(sizeof(char) + 1);
	st[0] = c;
	st[1] = '\0';
	ret = ft_atoi(st);
	free(st);
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
	config->data_type = int_type;
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
		return (dec_type);
	else if (c == 'i')
		return (int_type);
	else if (c == 'u')
		return (undec_type);
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
		else if (*(str) == '.')
		{
			str++;
			i++;
			if (ft_isdigit(*(str)))
				config->prec = get_int(*(str));
			else
				str--;
		}
		i++;
		str++;
	}
	config->data_type = read_type((*str));
	return (i + 1);
}
