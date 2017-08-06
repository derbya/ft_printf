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

typedef struct  s_args
{
	char		*storage;
	char		*flags;
	char		format;
	va_list		args;
}               t_args;

void			destroy_everything(t_args *e);
int				parse_flags(t_args *everything, char *str);
int				dispatcher(t_args *e);

#endif
