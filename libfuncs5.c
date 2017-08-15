/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfuncs5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 16:22:33 by aderby            #+#    #+#             */
/*   Updated: 2017/08/13 16:24:38 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char *str;

	str = dst;
	while (*src)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return (str);
}

void	ft_strdel(char **as)
{
	if (as)
	{
		free(*as);
		*as = NULL;
	}
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char    *str;

	if (s)
	{
		if (!(str = ft_strnew(len)))
			return (NULL);
		while (start--)
			s++;
		ft_strncpy(str, s, len);
		str[len] = '\0';
	}
	else
		str = NULL;
	return (str);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_atoi(const char *str)
{
	return ((int)ft_atoll(str));
}
