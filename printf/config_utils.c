/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:54:41 by aalzubai          #+#    #+#             */
/*   Updated: 2023/01/17 13:28:52 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*skipdigits(const char *str, int *i)
{
	while (ft_isdigit(*(str)))
	{
		str++;
		*i = *i + 1;
	}
	*i = *i - 1;
	return (str - 1);
}

int	check_simple_flags(const char *str, t_config *config)
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
	else
		return (0);
	return (1);
}

const char	*check_complex_flags(const char *str, t_config *config, int *i)
{
	if (ft_isdigit(*(str)))
	{
		config->wid = ft_atoi(str);
		str = skipdigits(str, i);
	}
	else if (*(str) == '.')
	{
		str++;
		*i += 1;
		config->prec = 1;
		if (ft_isdigit(*(str)))
		{
			config->precw = ft_atoi(str);
			str = skipdigits(str, i);
		}
		else
		{
			*i -= 1;
			str--;
		}
	}
	return (str);
}
