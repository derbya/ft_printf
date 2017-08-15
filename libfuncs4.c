/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfuncs4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 16:16:15 by aderby            #+#    #+#             */
/*   Updated: 2017/08/14 21:53:52 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*a;
	int				i;

	i = 0;
	a = b;
	while (len > 0)
	{
		a[i] = c;
		i++;
		len--;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_memalloc(size_t n)
{
	void	*mem;

	mem = (void *)malloc(n);
	if (mem == NULL)
		return (NULL);
	ft_memset(mem, 0, n);
	return (mem);
}
void	ft_putnbr(int n)
{
	char	c;

	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n == -2147483648)
	{
		n = 147483648;
		ft_putchar('2');
	}
	if (n / 10 > 0)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	ft_putchar(c);
}

char	*ft_strnew(size_t size)
{
	char	*ptr;

	if (!(ptr = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(ptr, size + 1);
	return (ptr);
}
