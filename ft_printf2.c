/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 14:43:31 by aderby            #+#    #+#             */
/*   Updated: 2017/08/05 16:30:00 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_flags(t_args *e, char *str)
{
	char    *flag;
	if (e->flags)
		ft_strclr(e->flags);
	if (*(str + 1) == ' ')
		return (0);
	else
		while (*str != ' ')
		{
			while (!(ft_strchr("iduoxXfFeEgGaAsSp%", *str)))
			{
				*flag = *str;
				flag++;
				str++;
			}
			ft_strjoin(e->flags, flag);
			e->format = *str;
			str++;
		}
	return (1);
}

int     digit(t_args *e)
{
	char *num;

	num = ft_itoa(va_arg(e->args, int));
	ft_strjoin(e->storage, num);
	return (1);
}

int     cands(t_args *e)
{
	char *tmp;
	if (e->format == 'c')
		*tmp = (char)va_arg(e->args, int);
	else if (e->format == 's')
		tmp = va_arg(e->args, char*);
	ft_strjoin(e->storage, tmp);
	return (1);
}

int     dispatcher(t_args *e)
{
	if (e->format == 'i' || e->format == 'd' || e->format == 'u')
		return (digit(e));
	//	else if (e->format == 'o')
	//		return (octal(e));
	//	else if (e->format == 'x' || e->format == 'X')
	//		return (hex(e));
	//	else if (e->format == 'f' || e->format == 'F')
	//		return (floatp(e));
	//	else if (e->format == 'e' || e->format == 'E')
	//		return (science(e));
	//	else if (e->format == 'g' || e->format == 'G')
	//		return (shortest(e));
	//	else if (e->format == 'a' || e->format == 'A')
	//		return (floatinghex(e));
	else if (e->format == 'c' || e->format == 's')
		return (cands(e));
	//	else if (e->format == 'p')
	//		return (pointer(e));
	//	else if (e->format == '%')
	//		return (percent(e));
	else
		return (0);
}
