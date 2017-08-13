/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 16:35:08 by aderby            #+#    #+#             */
/*   Updated: 2017/08/05 16:22:43 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/inc/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>
# include <stdint.h>

//remove this
# include <stdio.h>
//remove

# define PID print1->pid
# define FIELD_W print1->pid->fw
# define PFT (*print1)->type
# define PPID (*print1)->pid
# define F_ALT (*print1)->pid->fmt->uim

typedef union		u_format
{
	int		c;
	char		*s;
	void		*p;
	wchar_t		wc;
	wchar_t		*ws;
	intmax_t	im;
	uintmax_t	uim;
}               	t_format;

typedef struct		s_pid
{
	int		fw;
	int		prec;
	int		len;
	int		f_alt;
	int		f_zero;
	int		f_ladj;
	int		f_space;
	int		f_sign;
	int		base;
	int		xbase;
	union u_format	*fmt;
}			t_pid;

typedef struct		s_printf
{
	int		type;
	int		(*p_function)(struct s_printf *);
	char		*str;
	struct s_pid	*pid;
	struct s_printf	*next;
}			t_printf;

typedef struct		s_function
{
	int		(*f)(t_printf **, char *, int);
}			t_function;

void			destroy_everything(t_args *e);
int				parse_flags(t_args *everything, char *str);
int				dispatcher(t_args *e);

#endif
