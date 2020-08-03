# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/24 09:07:11 by ytomiyos          #+#    #+#              #
#    Updated: 2020/08/03 09:59:07 by ytomiyos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	libftprintf.a

LIBFT	=	libft/libft.a

SRCS	=	ft_printf.c \
			functions.c \
			flag_info.c

OBJS	=	$(SRCS:.c=.o)

LP_DIR	=	./libput

LP_S	=	put_c.c \
			put_d.c \
			put_d2.c \
			put_p.c \
			put_s.c \
			put_u.c \
			put_x.c

LP_O	=	$(addprefix $(LP_DIR)/, $(LP_S:.c=.o))


all		:	$(NAME)

$(NAME)	:	$(OBJS) $(LIBFT) $(LP_O)
			cp $(LIBFT) $(NAME)
			ar -rcs $(NAME) $(OBJS) $(LP_O)

$(LP_DIR)/%.o:	$(LP_DIR)/%.c
			$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
			cd "libft/" && make bonus

clean	:
			rm -f *.o
			rm -f $(LP_DIR)/*.o

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re