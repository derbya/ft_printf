/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfuncs6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 16:26:13 by aderby            #+#    #+#             */
/*   Updated: 2017/08/14 16:41:07 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static int	ft_check_space(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
				|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
			i++;
		else
			return (i);
	}
	return (i);
}

static int	ft_check_neg(int i, const char *str)
{
	if (str[i] == '-')
		return (-1);
	return (1);
}

long long	ft_atoll(const char *str)
{
	int			i;
	long long	res;
	int			isneg;

	res = 0;
	i = ft_check_space(str);
	isneg = ft_check_neg(i, str);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			res = res * 10 + str[i] - '0';
			i++;
		}
		else
			break ;
	}
	return (res * isneg);
}

char		*ft_strdup(const char *s1)
{
	char	*str;

	str = ft_strnew(ft_strlen(s1));
	if (!str)
		return (NULL);
	else
		return (ft_strcpy(str, s1));
}

char		*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (src[i] && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
