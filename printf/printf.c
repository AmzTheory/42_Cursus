/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:32:12 by aalzubai          #+#    #+#             */
/*   Updated: 2023/01/02 16:57:57 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	count_params(const char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		if (*str == '%')
			i++;
		str++;
	}
	return (i);
}

int	handle_conversion(const char *str, va_list ap)
{
	t_config	*con;
	int			count;

	con = create_config();
	count = read_config(con, str);
	// if (con->data_type == int_type)
	// 	return	()
	ft_putnbr_fd(va_arg(ap, int), 0);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;
	int		temp;

	count = 0;
	va_start(ap, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			temp = handle_conversion(str, ap);
			count += temp;
			str += temp;
		}
		else
		{
			ft_putchar_fd(*str, 1);
			str++;
			count++;
		}
	}
	va_end(ap);
	return (count);
}

int	main(void)
{
	t_config *con = create_config();
	const char *str = "%-6i";
	read_config(con, str);
	printf("zero: %i\ndash: %i\nhash: %i\nspace: %i\nplus:%i\nprec:%i\nwid:%i\ntype:%i\n" ,con->zero, con->dash, con->hash, con->space,con->plus,con->prec, con->wid, con->data_type);
	// ft_printf("%i- Ahmed %i- Saeed",1,2);
	// int v = 2;
	printf("%s---",getpre(con, 4, 6));
	// printf("%025.10f-Ahmed\n",f);
	// printf("%+i\n",v);
	// printf("% i\n",v);
	// printf("%0i\n",v);
}
