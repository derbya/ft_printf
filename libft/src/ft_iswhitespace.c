/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 15:20:28 by aderby            #+#    #+#             */
/*   Updated: 2017/06/13 18:09:51 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_iswhitespace(int c)
{
	if (c == ' ' || c == '\n' || c == '\v' || c == '\f'
			|| c == '\t' || c == '\r')
		return (1);
	return (0);
}
