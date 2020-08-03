/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 10:58:49 by ytomiyos          #+#    #+#             */
/*   Updated: 2020/08/02 15:37:49 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

static void	put_front(char *ptr, t_info *info, int *ans)
{
	int		len;
	int		space_len;

	len = ft_strlen(ptr);
	if (info->dot && (info->accuracy < len))
		len = info->accuracy;
	space_len = info->width - len;
	write(1, ptr, len);
	while ((space_len--) > 0 && (*ans += 1))
		write(1, " ", 1);
	*ans += len;
}

static void	put_back(char *ptr, t_info *info, int *ans)
{
	int		len;
	int		space_len;

	len = ft_strlen(ptr);
	if (info->dot && (info->accuracy < len))
		len = info->accuracy;
	space_len = info->width - len;
	while ((space_len--) > 0 && (*ans += 1))
		write(1, (info->zero ? "0" : " "), 1);
	write(1, ptr, len);
	*ans += len;
}

int			put_s(va_list *ap, t_info *info, int *ans, char **str)
{
	int		check;
	char	*ptr;

	check = 0;
	ptr = va_arg(*ap, char*);
	if (ptr == 0)
	{
		ptr = ft_strdup("(null)");
		check = 1;
	}
	if (info->minus)
		put_front(ptr, info, ans);
	else
		put_back(ptr, info, ans);
	if (check)
		free(ptr);
	*str += 1;
	return (0);
}
