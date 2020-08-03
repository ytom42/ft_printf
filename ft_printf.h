/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 09:07:08 by ytomiyos          #+#    #+#             */
/*   Updated: 2020/08/03 11:45:55 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_info
{
	int			minus;
	int			zero;
	int			width;
	int			dot;
	int			accuracy;
}				t_info;

int				ft_printf(const char *s, ...);
void			flaginfo(va_list *ap, t_info *info, char **str);
int				put_c(va_list *ap, t_info *info, int *ans, char **str);
int				put_s(va_list *ap, t_info *info, int *ans, char **str);
int				put_p(va_list *ap, t_info *info, int *ans, char **str);
int				put_d(va_list *ap, t_info *info, int *ans, char **str);
int				put_u(va_list *ap, t_info *info, int *ans, char **str);
int				put_x(va_list *ap, t_info *info, int *ans, char **str);
void			front_dot(char *ptr, t_info *info, int *ans, int minus);
void			front_not_dot(char *ptr, t_info *info, int *ans, int minus);
void			back_dot(char *ptr, t_info *info, int *ans, int minus);
void			back_not_dot(char *ptr, t_info *info, int *ans, int minus);
char			*ft_hextoa(size_t hex, int up);
char			*ft_uitoa(unsigned int n);

#endif
