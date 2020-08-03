/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 10:58:37 by ytomiyos          #+#    #+#             */
/*   Updated: 2020/08/03 09:47:39 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

static void	put_front(char c, int space_len, int *ans)
{
	write(1, &c, 1);
	while ((space_len--) > 0 && (*ans += 1))
		write(1, " ", 1);
}

static void	put_back(char c, int space_len, int *ans, int zero)
{
	while ((space_len--) > 0 && (*ans += 1))
		write(1, (zero ? "0" : " "), 1);
	write(1, &c, 1);
}

int			put_c(va_list *ap, t_info *info, int *ans, char **str)
{
	int				space_len;
	char			c;

	if (**str == 'c')
		c = va_arg(*ap, int);
	else
		c = '%';
	space_len = info->width - 1;
	if (info->minus)
		put_front(c, space_len, ans);
	else
		put_back(c, space_len, ans, info->zero);
	*ans += 1;
	*str += 1;
	return (0);
}
