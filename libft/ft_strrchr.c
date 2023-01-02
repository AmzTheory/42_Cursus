/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:28:15 by aalzubai          #+#    #+#             */
/*   Updated: 2022/12/14 09:44:30 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;
	char	ci;

	ci = (char) c;
	ret = 0;
	while (*s != '\0')
	{
		if (ci == *s)
			ret = (char *) s;
		s++;
	}
	if (ci == '\0')
		return ((char *) s);
	return (ret);
}
