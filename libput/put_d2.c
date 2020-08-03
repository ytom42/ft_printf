/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_d2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 12:09:32 by ytomiyos          #+#    #+#             */
/*   Updated: 2020/08/02 15:37:22 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

void	front_dot(char *ptr, t_info *info, int *ans, int minus)
{
	int		len;
	int		zero_len;
	int		space_len;

	len = ft_strlen(ptr);
	if (*ptr == '0' && len == 1 && info->dot)
		len = 0;
	zero_len = info->accuracy - len;
	space_len = info->width - (info->accuracy > len ? info->accuracy : len);
	if (minus && zero_len > 0)
		space_len -= 1;
	if (minus)
	{
		write(1, "-", 1);
		zero_len += 1;
	}
	while ((zero_len--) > 0 && (*ans += 1))
		write(1, "0", 1);
	if (minus)
		write(1, (ptr + 1), (len - 1));
	else
		write(1, ptr, len);
	while ((space_len--) > 0 && (*ans += 1))
		write(1, " ", 1);
	*ans += len;
}

void	back_dot(char *ptr, t_info *info, int *ans, int minus)
{
	int		len;
	int		zero_len;
	int		space_len;

	len = ft_strlen(ptr);
	if (*ptr == '0' && len == 1 && info->dot)
		len = 0;
	zero_len = info->accuracy - len;
	space_len = info->width - (info->accuracy > len ? info->accuracy : len);
	if (minus && zero_len > 0)
		space_len -= 1;
	while ((space_len--) > 0 && (*ans += 1))
		write(1, " ", 1);
	if (minus)
	{
		write(1, "-", 1);
		zero_len += 1;
	}
	while ((zero_len--) > 0 && (*ans += 1))
		write(1, "0", 1);
	if (minus)
		write(1, (ptr + 1), (len - 1));
	else
		write(1, ptr, len);
	*ans += len;
}

void	front_not_dot(char *ptr, t_info *info, int *ans, int minus)
{
	int		len;
	int		zero_len;
	int		space_len;

	len = ft_strlen(ptr);
	if (*ptr == '0' && len == 1 && info->dot)
		len = 0;
	zero_len = info->accuracy - len;
	space_len = info->width - len;
	if (minus && info->zero)
		write(1, "-", 1);
	if (minus && info->zero)
		write(1, (ptr + 1), (len - 1));
	else
		write(1, ptr, len);
	while ((space_len--) > 0 && (*ans += 1))
		write(1, (info->zero ? "0" : " "), 1);
	*ans += len;
}

void	back_not_dot(char *ptr, t_info *info, int *ans, int minus)
{
	int		len;
	int		zero_len;
	int		space_len;

	len = ft_strlen(ptr);
	if (*ptr == '0' && len == 1 && info->dot)
		len = 0;
	zero_len = info->accuracy - len;
	space_len = info->width - len;
	if (minus && info->zero)
		write(1, "-", 1);
	while ((space_len--) > 0 && (*ans += 1))
		write(1, (info->zero ? "0" : " "), 1);
	if (minus && info->zero)
		write(1, (ptr + 1), (len - 1));
	else
		write(1, ptr, len);
	*ans += len;
}
