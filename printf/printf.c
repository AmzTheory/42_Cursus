/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:32:12 by aalzubai          #+#    #+#             */
/*   Updated: 2023/01/04 18:28:36 by aalzubai         ###   ########.fr       */
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

int	handle_conversion(const char *str, va_list ap, int *count)
{
	t_config	*con;
	int			c;

	con = create_config();
	c = read_config(con, str);
	if (con->data_type == int_type)
		*count += handle_int(ap, con);
	// ft_putnbr_fd(va_arg(ap, int), 0);
	return (c);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		out_count;
	int		con_count;

	out_count = 0;
	va_start(ap, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			con_count = handle_conversion(str, ap, &out_count);
			str += con_count;
		}
		else
		{
			ft_putchar_fd(*str, 1);
			str++;
			out_count++;
		}
	}
	va_end(ap);
	return (out_count);
}

int	main(void)
{
	// t_config *con = create_config();
	// const char *str = "%-6i";
	// read_config(con, str);
	// printf("zero: %i\ndash: %i\nhash: %i\nspace: %i\nplus:%i\nprec:%i\nwid:%i\ntype:%i\n" ,con->zero, con->dash, con->hash, con->space,con->plus,con->prec, con->wid, con->data_type);
	// int v = 22;
	// test single int conversion with bonus
	printf("\n %i == %i", printf("%i",22), ft_printf("%i", 22));
	// printf("\n %i == %i", printf("%i = ",-22), ft_printf("%i", -22));
	// int v = 2;
	// printf("%s---",getsuf(con, 4));
	// printf("%025.10f-Ahmed\n",f);
	// printf("%-5i--\n",v);
	// printf("% i\n",v);
	// printf("%0i\n",v);
}
