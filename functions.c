/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 09:20:51 by ytomiyos          #+#    #+#             */
/*   Updated: 2020/07/30 20:24:31 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

char		*ft_uitoa(unsigned int n)
{
	int				len;
	char			*ptr;
	unsigned int	tmp;

	len = 0;
	tmp = n;
	if (tmp == 0)
		len++;
	while (tmp > 0 && ++len)
		tmp = tmp / 10;
	if (!(ptr = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ptr[len] = '\0';
	while (len--)
	{
		ptr[len] = n % 10 + '0';
		n = n / 10;
	}
	return (ptr);
}

char		*ft_hextoa(size_t hex, int up)
{
	int		c;
	int		len;
	char	*str;
	char	*ptr;
	size_t	tmp;

	len = 0;
	str = "0123456789abcdef";
	if ((tmp = hex) == 0)
		len++;
	while (tmp > 0 && ++len)
		tmp = tmp / 16;
	if (!(ptr = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ptr[len] = '\0';
	while (len >= 0 && len--)
	{
		c = str[hex % 16];
		if (up == 1 && ft_isalpha(c))
			ptr[len] = c - 32;
		else
			ptr[len] = c;
		hex /= 16;
	}
	return (ptr);
}
