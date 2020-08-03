/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 10:58:53 by ytomiyos          #+#    #+#             */
/*   Updated: 2020/08/02 15:38:07 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

static void	put_front(char *ptr, t_info *info, int *ans)
{
	int		len;
	int		zero_len;
	int		space_len;

	len = ft_strlen(ptr);
	if (*ptr == '0' && len == 1 && info->dot)
		len = 0;
	zero_len = info->accuracy - len;
	space_len = info->width - (info->accuracy > len ? info->accuracy : len);
	while ((zero_len--) > 0 && (*ans += 1))
		write(1, "0", 1);
	write(1, ptr, len);
	while ((space_len--) > 0 && (*ans += 1))
		write(1, (info->zero ? "0" : " "), 1);
	*ans += len;
}

static void	put_back(char *ptr, t_info *info, int *ans)
{
	int		len;
	int		zero_len;
	int		space_len;

	len = ft_strlen(ptr);
	if (*ptr == '0' && len == 1 && info->dot)
		len = 0;
	zero_len = info->accuracy - len;
	space_len = info->width - (info->accuracy > len ? info->accuracy : len);
	while ((space_len--) > 0 && (*ans += 1))
		write(1, (info->zero && !(info->dot) ? "0" : " "), 1);
	while ((zero_len--) > 0 && (*ans += 1))
		write(1, "0", 1);
	write(1, ptr, len);
	*ans += len;
}

int			put_x(va_list *ap, t_info *info, int *ans, char **str)
{
	char			*ptr;
	unsigned int	u_n;

	u_n = va_arg(*ap, unsigned int);
	if (**str == 'x')
		ptr = ft_hextoa(u_n, 0);
	else
		ptr = ft_hextoa(u_n, 1);
	if (!ptr)
		return (-1);
	if (info->minus)
		put_front(ptr, info, ans);
	else
		put_back(ptr, info, ans);
	free(ptr);
	*str += 1;
	return (0);
}
