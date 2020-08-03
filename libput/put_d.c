/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 10:58:42 by ytomiyos          #+#    #+#             */
/*   Updated: 2020/08/02 14:51:05 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

static void	put_front(char *ptr, t_info *info, int *ans, int minus)
{
	if (info->dot)
		front_dot(ptr, info, ans, minus);
	else
		front_not_dot(ptr, info, ans, minus);
}

static void	put_back(char *ptr, t_info *info, int *ans, int minus)
{
	if (info->dot)
		back_dot(ptr, info, ans, minus);
	else
		back_not_dot(ptr, info, ans, minus);
}

int			put_d(va_list *ap, t_info *info, int *ans, char **str)
{
	int		n;
	int		minus;
	char	*ptr;

	minus = 0;
	n = va_arg(*ap, int);
	if (n < 0)
		minus = 1;
	if (!(ptr = ft_itoa(n)))
		return (-1);
	if (info->minus)
		put_front(ptr, info, ans, minus);
	else
		put_back(ptr, info, ans, minus);
	free(ptr);
	*str += 1;
	return (0);
}
