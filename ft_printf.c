/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 14:24:54 by ytomiyos          #+#    #+#             */
/*   Updated: 2020/08/03 19:10:11 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		output(va_list *ap, t_info *info, char **str, int *ans)
{
	int		n;

	n = 0;
	if (**str == 'c' || **str == '%')
		n = put_c(ap, info, ans, str);
	else if (**str == 's')
		n = put_s(ap, info, ans, str);
	else if (**str == 'p')
		n = put_p(ap, info, ans, str);
	else if (**str == 'd' || **str == 'i')
		n = put_d(ap, info, ans, str);
	else if (**str == 'u')
		n = put_u(ap, info, ans, str);
	else if (**str == 'x' || **str == 'X')
		n = put_x(ap, info, ans, str);
	if (n == -1)
	{
		va_end(*ap);
		return (-1);
	}
	return (0);
}

int		ft_printf(const char *s, ...)
{
	int			ans;
	char		*str;
	va_list		ap;
	t_info		info;

	ans = 0;
	va_start(ap, s);
	str = (char *)s;
	while (*str)
	{
		if (*str == '%')
		{
			flaginfo(&ap, &info, &str);
			if (output(&ap, &info, &str, &ans) == -1)
				return (-1);
		}
		else
		{
			write(1, str++, 1);
			ans += 1;
		}
	}
	va_end(ap);
	return (ans);
}
