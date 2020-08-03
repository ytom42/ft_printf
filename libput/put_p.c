/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 10:58:47 by ytomiyos          #+#    #+#             */
/*   Updated: 2020/08/02 15:37:05 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

static void	put_front(char *ptr, t_info *info, int *ans)
{
	int		len;
	int		space_len;

	len = ft_strlen(ptr);
	space_len = info->width - len - 2;
	write(1, "0x", 2);
	write(1, ptr, len);
	while ((space_len--) > 0 && (*ans += 1))
		write(1, " ", 1);
	*ans += len + 2;
}

static void	put_back(char *ptr, t_info *info, int *ans)
{
	int		len;
	int		zero_len;
	int		space_len;

	len = ft_strlen(ptr);
	if (*ptr == '0' && len == 1 && info->dot)
		len = 0;
	space_len = info->width - len - 2;
	zero_len = info->accuracy - len;
	while ((space_len--) > 0 && (*ans += 1))
		write(1, " ", 1);
	write(1, "0x", 2);
	while ((zero_len--) > 0 && (*ans += 1))
		write(1, "0", 1);
	write(1, ptr, len);
	*ans += len + 2;
}

int			put_p(va_list *ap, t_info *info, int *ans, char **str)
{
	char			*ptr;
	size_t			hex;

	hex = (size_t)va_arg(*ap, void*);
	if (!(ptr = ft_hextoa(hex, 0)))
		return (-1);
	if (ptr == 0)
		ptr = ft_strdup("(null)");
	if (info->minus)
		put_front(ptr, info, ans);
	else
		put_back(ptr, info, ans);
	free(ptr);
	*str += 1;
	return (0);
}
