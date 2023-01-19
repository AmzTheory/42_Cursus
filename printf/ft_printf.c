/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:32:12 by aalzubai          #+#    #+#             */
/*   Updated: 2023/01/17 15:36:15 by aalzubai         ###   ########.fr       */
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

int	handle_percent(void)
{
	char	*c;

	c = "%";
	return (put_str(c));
}

int	handle_conversion(const char *str, va_list ap, int *count)
{
	t_config	*con;
	int			c;
	int			count_test;

	con = create_config();
	if (!con)
		return (-1);
	c = read_config(con, str);
	if (con->data_type == i_type || con->data_type == d_type)
		count_test = handle_int(ap, con);
	else if (con->data_type == u_type)
		count_test = handle_unsignedint(ap, con);
	else if (con->data_type == str_type)
		count_test = handle_string(ap, con);
	else if (con->data_type == char_type)
		count_test = handle_char(ap, con);
	else if (con->data_type == perce_type)
		count_test = handle_percent();
	else if (con->data_type == lowerhex_type)
		count_test = handle_hex(ap, con, 'a');
	else if (con->data_type == upperhex_type)
		count_test = handle_hex(ap, con, 'A');
	else if (con->data_type == ptr_type)
		count_test = handle_ptr(ap, con);
	else
		count_test = -1;
	free(con);
	if (count_test == -1)
		return (-1);
	*count += count_test;
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
			if (con_count == -1)
				return (-1);
			str += con_count;
		}
		else
		{
			// ft_putchar_fd(*str, 1);
			if (write(1, str, 1) == -1)
				return (-1);
			str++;
			out_count++;
		}
	}
	va_end(ap);
	return (out_count);
}
#include <fcntl.h>
int main()
{
	// unsigned int val = 0;
	// printf("len = %u \n"		, ft_printf("%.0X", 0));
	// printf("len = %u \n", printf("%.0X", 0));
	// Write C code here
    ft_printf("%i\n",4);
	// printf("n = %i",77);
}
