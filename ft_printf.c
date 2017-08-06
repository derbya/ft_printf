/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 16:32:29 by aderby            #+#    #+#             */
/*   Updated: 2017/08/05 16:33:22 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		destroy_everything(t_args *e)
{
	if (e->storage)
		free(e->storage);
	if (e->flags)
		free(e->flags);
}

void		initialize_everything(t_args *e, const char *fmt)
{
	e->storage = ft_strnew(0);
	e->flags = ft_strnew(0);
	e->format = '\0';
}

static int	print_everything(const char *str)
{
	int i;

	i = ft_strlen(str);
	ft_putstr(str);
	return (i);
}

int			found_flag(t_args *e, char *str, const char *fmt)
{
	int		ret;
	char	*tmp;

	tmp = (char *)fmt;
	ft_strjoin(e->storage, str);
	ft_putstr(e->storage);
	ft_putstr("\n");
	ret = parse_flags(e, tmp);
	if (ret == 0)
		return (0);
	if ((ret = dispatcher(e)) == 0)
	{
		destroy_everything(e);
		return (0);
	}
	return (ret);
}

int			ft_printf(const char *fmt, ...)
{
	t_args  everything;
	char    *tmpstorage;
	char    *tmp;
	int     ret;

	va_start(everything.args, fmt);
	initialize_everything(&everything, fmt);
	tmp = tmpstorage;
	while (*fmt)
	{
		if (*fmt != '%')
			*tmpstorage++ = *fmt;
		else
		{
			if (!(found_flag(&everything, tmp, fmt)))
				return (0);
			ft_strclr(tmpstorage);
		}
		fmt++;
	}
	va_end(everything.args);
	ret = print_everything(everything.storage);
	destroy_everything(&everything);
	return (ret);
}

int		main(void)
{
	ft_printf("words %s more words %i and a number", "string", 33);
}
