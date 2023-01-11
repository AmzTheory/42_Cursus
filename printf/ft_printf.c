/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:32:12 by aalzubai          #+#    #+#             */
/*   Updated: 2023/01/11 12:22:05 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	handle_percent()
{
	char	*c;

	c = "%";
	return (put_str(c));
}

int	handle_conversion(const char *str, va_list ap, int *count)
{
	t_config	*con;
	int			c;

	con = create_config();
	c = read_config(con, str);
	if (con->data_type == i_type)
		*count += handle_int(ap, con);
	else if (con->data_type == d_type)
		*count += handle_int(ap, con);
	else if (con->data_type == u_type)
		*count += handle_unsignedint(ap, con);
	else if (con->data_type == str_type)
		*count += handle_string(ap, con);
	else if (con->data_type == char_type)
		*count += handle_char(ap, con);
	else if (con->data_type == perce_type)
		*count += handle_percent();
	else if (con->data_type == lowerhex_type)
		*count += handle_hex(ap, con, 'a');
	else if (con->data_type == upperhex_type)
		*count += handle_hex(ap, con, 'A');
	else if (con->data_type == ptr_type)
		*count += handle_ptr(ap, con);
	free(con);
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
// #include <limits.h>

// int	main(void)
// {
	// t_config *con = create_config();
	// const char *str = "%5s";
	// read_config(con, str);
	// printf("zero: %i\ndash: %i\nhash: %i\nspace: %i\nplus:
	// %i\nprec:%i\nwid:%i\ntype:%i\n" ,
	// con->zero, con->dash, con->hash, con->space,con->plus
	// ,con->prec, con->wid, con->data_type);
	// int v = 22;
	// printf("\n%i\n",ft_printf("%-5c-%-10c",'A','B'));
	// printf("\n len = %i\n",ft_printf("%"));
	// char *str = "Ahmed";
	// printf("\n len = %i\n",ft_printf("%p",0));
	// printf("\n len = %i\n",printf("%p",(void *)0));
	// test single int conversion with bonus
	// printf("\n1: %i == %i\n", printf("%i",22), ft_printf("%i^", 22)-1);
	// printf("\n2: %i == %i\n", printf("%i",-22), ft_printf("%i^", -22)-1);
	// printf("\n3: %i == %i\n", printf("%+i",22), ft_printf("%+i^", 22)-1);
	// printf("\n4: %i == %i\n", printf("%+i",-22), ft_printf("%+i^", -22)-1);
	// printf("\n5: %i == %i\n", printf("%-5i",22), ft_printf("%-5i^", 22)-1);
	// printf("\n6:%i == %i\n", printf("%-12i",-22), ft_printf("%-12i^", -22)-1);
	// printf("\n7:%i == %i\n", printf("% 5i",22), ft_printf("% 5i^", 22)-1);
	// printf("\n8:%i == %i\n", printf("%-+i",22), ft_printf("%-+i^", 22)-1);
	// printf("\n7:%i == %i\n", printf("%05i",22), ft_printf("%05i^", 22)-1);
	// printf("\n8:%i == %i\n", printf("%-+i",22), ft_printf("%-+i^", 22)-1);

	//error cases
	// printf("\n9:%i == %i\n", printf("%-0i",22), ft_printf("%-0i^", 22)-1);
	// printf("%-6i^", 22);
	// printf("\n9:%i == %i\n", printf("% 5i",22), ft_printf("% 5i^", 22)-1);
	// printf("\n %i == %i", printf("%i = ",-22), ft_printf("%i", -22));
	// int v = 2;
	// printf("%s---",getsuf(con, 4));
	// printf("%025.10f-Ahmed\n",f);
	// printf("%-5i--\n",v);
	// printf("% i\n",v);
	// printf("%0i\n",v);
// }
