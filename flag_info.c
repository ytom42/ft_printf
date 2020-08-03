/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 10:02:38 by ytomiyos          #+#    #+#             */
/*   Updated: 2020/08/03 11:47:04 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	flaginfo_init(t_info *info)
{
	info->minus = 0;
	info->zero = 0;
	info->width = 0;
	info->dot = 0;
	info->accuracy = 0;
}

void	flaginfo_width_num(t_info *info, char **str)
{
	int		width;

	width = 0;
	if (**str == '0')
	{
		info->zero = 1;
		*str += 1;
		if (**str == '-')
		{
			info->zero = 0;
			info->minus = 1;
			*str += 1;
		}
	}
	while (**str >= 48 && **str <= 57)
	{
		width = (width * 10) + (**str - 48);
		*str += 1;
	}
	info->width = width;
}

void	flaginfo_width(va_list *ap, t_info *info, char **str)
{
	while (**str == '+' || **str == '-' || **str == '*' \
	|| (**str >= 48 && **str <= 57))
	{
		flaginfo_width_num(info, str);
		if (**str == '-')
		{
			info->minus = 1;
			*str += 1;
		}
		if (**str == '*')
		{
			info->width = va_arg(*ap, int);
			if (info->width < 0)
			{
				info->minus = 1;
				info->zero = 0;
				info->width = -(info->width);
			}
			*str += 1;
		}
		if (**str == '+')
			*str += 1;
	}
}

void	flaginfo_accuracy(va_list *ap, t_info *info, char **str)
{
	int		accuracy;

	if (**str == '.')
	{
		*str += 1;
		info->dot = 1;
	}
	accuracy = 0;
	while (**str >= 48 && **str <= 57)
	{
		accuracy = (accuracy * 10) + (**str - 48);
		*str += 1;
	}
	if (info->dot)
		info->accuracy = accuracy;
	if (**str == '*')
	{
		info->accuracy = va_arg(*ap, int);
		if (info->accuracy < 0)
			info->dot = 0;
		*str += 1;
	}
}

void	flaginfo(va_list *ap, t_info *info, char **str)
{
	*str += 1;
	flaginfo_init(info);
	flaginfo_width(ap, info, str);
	flaginfo_accuracy(ap, info, str);
}
