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
//libft stuff

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

void	ft_putchar(const char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *s)
{
	if (s)
		write(1, s, ft_strlen(s));
}

void	ft_putendl(const char *s)
{
	ft_putstr(s);
	ft_putchar('\n');
}
/* use my putnbr
void	ft_putnbr(int n)
{
	int sign;

	sign = 0;
	if (n == -2147483648)
	{
		sign = 1;
		n += 1;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		if (sign == 1)
		ft_putchar
	}
}*/

//copy my strenew
//strcoy
//strdel
char	*ft_strfresize(char **s, size_t newsize)
{
	char *tmp;
	if (!(tmp = ft_strnew(newsize)))
		return (NULL);
	ft_strcpy(tmp, *s);
	ft_strdel(s);
	return (tmp);
}

//strsub
int	ft_iswhitespace(int c)
{
	if (c == ' '|| c == '\n' || c == '\t' || c == '\v' || c == '\r' || c == '\f')
			return (1);
	return (0);
}
//is digit
//atoi
//strdup

char	*ft_strfremalloc(char **s)
{
	char *new;

	if (!(new = ft_strdup(*s)))
		return (NULL);
	free(*s);
	*s = NULL;
	return (new);
}

size_t	ft_putchars(const char c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		ft_putchar(c);
		i++;
	}
	return (i);
}

char	*ft_strofchars(const char c, size_t num)
{
	char	*new;
	size_t	i;

	if (!(new = ft_Strnew(num)))
		return (NULL);
	i = 0;
	while (i < num)
	{
		new[i] = c;
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strfjoin(char **s1, const char *s2)
{
	char	*new;
	int	i;
	int	j;

	i = 0;
	j = i;
	if (*s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(new = ft_strnew(ft_strlen((char *)*s1) + ft_strlen((char *)s2))))
		return (NULL);
	while ((*s1)[i])
	{
		new[i] = (*s1)[i];
		i++;
	}
	while (s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	ft_strdel(s1);
	return (new);
}

void	ft_strtolower(char **s)
{
	int i;

	i = 0;
	if (*s)
	{
		while (s[o][i])
		{
			if (s[0][i] > 64 && s[0][i] < 91)
				s[0][i] += 32;
			i++;
		}
	}
}

void	ft_strdeltwo(char **s, char **s2)
{
	ft_strdel(s);
	ft_strdel(s2);
}
void	ft_strdelthree(char **s, char **s2, char **s3)
{
	ft_strdel(s);
	ft_strdel(s2);
	ft_strdel(s3);
}

char	*ft_strffjoin(char **s1, char **s2)
{
	char	*new;
	int	i;
	int	j;

	i = 0;
	j = i;
	if (*s1 == NULL || *s2 == NULL)
		return (NULL);
	if (!(new = ft_strnew(ft_strlen((char *)*s1) + ft_strlen((char *)s2))))
		return (NULL);
	while ((*s1)[i])
	{
		new[i] = (*s1)[i];
		i++;
	}
	while ((*s2)[j])
		new[i++] = (*s2)[j++];
	new[i] = '\0';
	ft_strdeltwo(s1, s2);
	return (new);
}

//whar section

size_t		ft_wstrlen(wchar_t *s)
{
	wchar_t *tmp;

	tmp = s;
	while (*tmp)
		tmp++;
	return (p - s);
}

int		num_of_bytes(unsigned int ui)
{
	if (ui <= 127)
		return (1);
	else if (ui <= 2047)
		return (2);
	else if (ui <= 65535)
		return (3);
	return (4);
}

wchar_t		*ft_wstrsub(wchar_t *ws, size_t, start, size_t len)
{
	wchar_t *new;
	size_t	i;

	if (ws == NULL)
		return (NULL);
	i = 0;
	if (!(new = ft_wstrnew(len)))
		return (NULL);
	while (ws[start] && i < len)
	{
		new[i] = ws[start];
		i++;
		start++;
	}
	new[i] = L'\0';
	return (new);
}

void		ft_putwchar(wchar_t wi)
{
	unsigned int ui;

	ui = (unsigned int)wi;
	if (ui < 128)
		ft_putchar(ui);
	else if (ui < 2048)
	{
		ft_putchar(192 | (ui >> 6 & 63));
		ft_putchar(128 | (ui & 63));
	}
	else if (ui < 65536)
	{
		ft_putchar(224 | (ui >> 12 & 63));
		ft_putchar(128 | (ui >> 6 & 63));
		ft_putchar(128 | (ui & 63));
	}
	else
	{
		ft_putchar(240 | (ui >> 18 & 63));
		ft_putchar(128 | (ui >> 12 & 63));
		ft_putchar(128 | (ui >> 6 & 63));
		ft_putchar(128 | (ui & 63));
	}
}

wchar_t	*ft_wstrdup(wchar_t *ws)
{
	wchar_t *tmp;
	int	i;

	if (!(tmp = ft_wstrnew(ft_wstrlen(ws))))
		return (NULL);
	i = 0;
	while (ws[i])
	{
		tmp[i] = ws[i];
		i++;
	}
	tmp[i] = L'\0';
	return (tmp);
}

void	ft_putwstr(wchar_t *ws)
{
	int i;

	i = 0;
	while (ws[i])
		ft_putwchar(ws[i++]);
}


//
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char 	*a;
	int		i;

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
	ft_memset(s, '\0', n)
}

void	*ft_memalloc(void *s, size_t n)
{
	void	*mem;

	mem = (void *)malloc(size);
	if (mem == NULL)
		return (NULL);
	ft_memset(mem, 0, size);
	return (mem);
}


// end of libft stuff
//freeing stuff and might now need all of this

void	fre_printf_datafmt(t_datafmt **fmt, int type)
{
	if (type == S_TYPE || type == WS_TYPE)
		ft_strdel(&((*fmt)->s));
	if (*fmt)
	{
		free(*fmt);
		*fmt = NULL;
	}
}
void	free_printf_precentid(t_percentid **pid)
{
	if (*pid)
	{
		free(*pid);
		*pid = NULL;
	}
}
void	free_all(t_printf **head)
{
	t_printf *tmo;
	if (*head)
	{
		while (*head)
		{
			if ((*head)->type == STRING_TYPE)
				ft_strdel(&((*head)->str));
			else if ((*head)->type != -1)
			{
				free_printf_datafmt(&((*head)->pid->fmt), (*head)->type);
				free_printf_percentid(&((*head)->pid));
			}
			tmp = *head;
			*head = (*head)->next;
			free(tmp);
		}
	}
}


//set percent id stuff
/*
** set initial flags -
** # : alternate form (ocatl prints 066, 034/// | hex prints 0x66, 0x34...)
** 0 : fill field with 0's
** - : fill the left space with fw chars
** ' ' : leave blnk before psitive number
** + : must place a sign
*/
int		set_flags(t_printf **print1, char *s, int j)
{
	while (s[j] == '#' || s[j] == '0' || s[j] == '-' || s[j] == ' ' || s[j] == '+')
	{
		if (s[j] == '#')
			(*print1)->pid->f_alt = 1;
		if (s[j] == '0')
			(*print1)->pid->f_zero = 1;
		if (s[j] == '-')
			(*print1)->pid->f_ladj = 1;
		if (s[j] == ' ')
			(*print1)->pid->f_space = 1;
		if (s[j] == '+')
			(*print1)->pid->f_sign = 1;
		j++;
	}
	return (j);
}
int		set_fieldwidth(t_printf **print1, char *s, int j)
{
	int	fw;

	fw = 0;
	if (ft_isdigit(s[j]))
		fw = ft_atoi(&s[j]);
	while (ft_isdigit(s[j]))
		j++;
	if (fw > 0)
		(*print1)->pid-:fw = fw;
	return (j);
}
int		set_length(t_printf **prtin1, char *s, int j)
{
	if (ft_islengthchar(s[j]))
	{
		if ((s[j] == 'h' && s[j +1] == 'h') || (s[j] == 'l' && s[j + 1] == 'l'))
		{
			if (s[j] + 1 == 'h')
				(*print1)->pid->len = L_HH;
			else if (s[j +1] == 'l')
				(*prtin1)->pid->len = L_LL;
			return (j + 2);
		}
		else if (s[j] == 'h')
			(*print1)->pid->len = L_H;
		else if (s[j] == 'l')
			(*print1)->pid->len = L_L;
		else if (s[j] == 'j')
			(*print1)->pid->len = L_J;
		else if (s[j] == 'z')
			(*print1)->pid->len = L_Z;
		return (j + 1);
	}
	return (j);
}
int		set_type(t_printf **prtin1, char *s, int j)
{
	if (ft_isconversionchar(s[j]))
	{
		(*print1)->type = ((s[j] == 's' || s[j] == 'S') ? S_TYPE : (*print1)->type);
		(*print1)->type = ((s[j] == 'c' || s[j] == 'C') ? C_TYPE : (*print1)->type);
		(*print1)->type = ((s[j] == 'd' || s[j] == 'i') ? DI_TYPE : (*print1)->type);
		(*print1)->type = ((s[j] == 'D' ? DD_TYPE : (*print1)->type);
		(*print1)->type = ((s[j] == 'o' ? O_TYPE : (*print1)->type);
		(*print1)->type = ((s[j] == 'O' ? OO_TYPE : (*print1)->type);
		(*print1)->type = ((s[j] == 'u' ? U_TYPE : (*print1)->type);
		(*print1)->type = ((s[j] == 'U' ? UL_TYPE : (*print1)->type);
		(*print1)->type = ((s[j] == 'x' ? X_TYPE : (*print1)->type);
		(*print1)->type = ((s[j] == 'X' ? XX_TYPE : (*print1)->type);
		(*print1)->type = ((s[j] == 'p' ? P_TYPE : (*print1)->type);
		(*print1)->type = ((s[j] == '%' ? PCNT_TYPE : (*print1)->type);
		(*print1)->type = ((s[j] == 'b' ? B_TYPE : (*print1)->type);
		(*print1)->type = ((s[j] == 'B' ? BB_TYPE : (*print1)->type);
		(*print1)->pid->base = (s[j] == 'x' || s[j] == 'X' ? 16 : (*print1)->pid->base);
		(*print1)->pid->base = (s[j] == 'o' || s[j] == 'O' ? 8 : (*print1)->pid->base);
		(*print1)->pid->base = (s[j] == 'b' || s[j] == 'B' ? 2 : (*print1)->pid->base);
		(*print1)->pid->xbase = (s[j] == 'X' ? 1 : -1);
		F_ALT = (s[j] == 'x' || s[j] == 'X') && F_ALT != -1 ? 16 : F_ALT;
		F_ALT = (s[j] == 'o' || s[j] == 'O') && F_ALT != -1 ? 8 : F_ALT;
		return ((*print1)->type == -1? -1 : j + 1);
	}
	return (-1);
}

//set helper stuff
int		ft_islengthchar(int c)
{
	size_t	len;

	len = ft_strlen(LENGTHS);
	while (len--)
		if (c == LENGTHS[len])
			return (1);
	return (0);
}
int		ft_isconverstionchar(int c)
{
	size_t len;

	len = ft_strlen(CONVERSIONS);
	while (len--)
		if (c == CONVERSIONS[len])
			return (1);
	return (0);
}
int		ft_isnumericconversionchar(int c)
{
	size_t len;

	len = ft_strlen(NUM_CONVERSIONS);
	while (len--)
		if (c == NUM_CONVERSIONS[len])
			return (1);
	return (0);
}



//wide string stuff, place with wide char if possible
static wchar_t	*adjust_precision(wchar_t **ws, int precision)
{
	wchar_t *tmp;

	if (!(tmp = ft_wstrsub(*ws, 0, precision)))
		return (NULL);
	free(*ws);
	*ws = NULL;
	return (tmp);
}
int		pf_widestr(t_printf *print1)
{
	char	*fw;
	int	len;
	int	n;

	len = ft_wstrlen(print1->pid->fmt->ws);
	if (print1->pid->precision != -1)
		if (!(PID->fmt->ws = adjust_precision(&(PID->fmt->ws), PID->precision)))
			return (-1);
	n = PID->fw - ft_wstrlen(PID->fmt->ws);
	if (n > 0)
		if (!(fw = ft_strofchars(' ', n)))
			return (-1);
	if (PID->f_ladj != -1)
		ft_putwstr(PID->fmt->ws);
	n > 0 ? ft_putstr(fw) : 0;
	if (PID->f_ladj == -1)
		ft_putwstr(PID->fmt->ws);
	return (ft_wstrlen(PID->fmt->ws) + (n > 0 ? ft_strlen(fw) : 0));
}


//wide char stuff place with widestro if possible
int		pf_widechar(t_printf *prtin1)
{
	int	fw;

	fw = 0;
	if (print1->pid->f_ladj != -1)
	{
		ft_putwchar(prtin1->pid->fmt->wc);
		while (++fw < print1->pid->fw)
			ft_putchar(' ');
	}
	else
	{
		while (++fw < print1->pid->fw)
			ft_putchar(' ');
		ft_putwchar(prtin1->pid0>fmt->wc);
	}
	return (fw);
}

//double chack didn't looks too carfully. place above everything in unsignedint stuff
static char	*ft_uintmax_to_ascii(uintmax_t val, int base, int xbase)
{
	int	s_len;
	char	*b_array;
	char	*s;
	uintmax_t	tmp_val;

	b_array = "0123456789ABCDEF";
	tmp_val = val;
	s_len = 0;
	while (++s_len && tmp_val >= (intmax_t)base)
		tmp_val /= base;
	if (!(s = ft_strnew(s_len)))
		return (NULL);
	while (s_len--)
	{
		s[s_len] = b_array[val % base];
		val /= base;
	}
	(xbase == -1) ? ft_strtolower(&s) : 0;
	return (s);
}

//fix line length issues and place in the unsignedint stuff as static int type
static int	add_fieldwidth(char **str, char **chars, t_printf *print1)
{
	char *tmp;
	char *tmp2;

	if (chars[0][0] == '0')
	{
		if (print1->pid->alt == 16 || prtin1->pid->f_alt == 8)
		{
			tmp = ft_strsub(*str, 0, (print1->pid->f_a;t == 16 ? 2: 1));
			tmp2 = ft_strsub(*str, (print1->pid,f_alt == 16 ? 2: 1), ft_strlen(*str) - (print1->pid->f_alt == 16 ? 2 : 1));
			tmp = ft_strffjoin(&tmp, chars);
			tmp = ft_strffjoin(&tmp, &tmp2);
		}
		else
			tmp = ft_strffjoin(chars, str);
	}
	else
	{
		tmp = ft_Strffjoin((print1->pid->f_ladj != -1 ? str : chars), (print1->pid->f_ladj != -1 ? chars : str));
	}
	*str = tmp;
	return (ft_strlen(*str));
}

//double check these things place it with unsigned int as static int return type
static int	add_alt(char **str, int xbase, int f_alt, int type)
{
	char	*alt;

	if ((f_alt == 16 && ft_strlen(*str) > 0 && (*str)[0] != '0') || type == P_TYPE || type == BB_TYPE)
	{
		if (!(alt = ft_strnew(2)))
			return (-1);
		alt[0] = '0';
		alt[1] = xbase != -1 ? 'X' : 'x';
		alt[1] = (type == BB_TYPE) ? 'b' : alt[1];
		if (!(*str = ft_strffjoin(&alt, str)))
			return (-1);
	}
	else if (f_alt == 8)
	{
		if ((*str)[0] != '0')
		{
			if (!(alt = ft_strnew(1)))
				return (-1);
			alt[0] = '0';
			if (!(*str = ft_strffjoin(&alt, str)))
				return (-1);
		}
	}
	return (ft_strlen(*str));
}

//place above of unsignedint as static int
static int	add_prec(char **str, int zeros, int alt)
{
	char	*tmp;

	if (zeros > 0)
	{
		if (!(tmp = ft_strofchars('0', zeros)))
			return (-1);
		if (!(*str = ft_strffjoin(&tmp, str)))
			return (-1);
	}
	else if (alt == 8)
	{
		if ((ad_alt(str, 0, alt, -1)) == -1)
			return (-1);
	}
	return (ft_strlen(*str));
}

// place inside it's own file unsignedint and also fix the line limit
int		pf_unsignedint(t_printf *print1)
{
	char	*s;
	char	*tmp;
	char	pad;
	int	s_len;

	if (!(s = (PID->precision == 0 && PID->base != 10 && PID->fmt->uim == 0 ? ft_strnew(0) : ft_uintmax_to_ascii(PID->fmt->uim, PID->base, PID->xbase))))
		return (-1);
	pad = (PID->f_zero != -1 ? '0' : ' ');
	s_len = ft_strlen(s);
	if (PID->precision > s_len || PID->f_alt == 8)
		if ((s_len = add_prec(&s, PID->precision - s_len, PID->f_alt)) = -1)
			return (-1);
	if (PID->f_alt != -1 && (PID->base = =16 || PID->base == 2))
		if ((s_len = add_alt(&s, PID->x_base, PID->f_alt, print1->type)) == -1)
			return (-1);
	if (PID->fw > s_len)
	{
		tmp = ft_strofchars(pad, print1->pid->fw - s_len);
		if ((s_len = add_fieldwidtch(&s, &tmp, print1)) == -1)
			return (-1);
	}
	ft_putstr(s);
	return (s_len);
}

//for pf string fieldwidth
static char	*add_fieldwidth(char **s, int f_ladj, int spaces)
{
	char *tmp;

	if (!(tmp = ft_strofchars(' ', spaces)))
		return (NULL);
	if (f_ladj != -1)
	{
		if (1(*s = ft_strfjoin(s, tmp)))
			return (NULL);
		ft_strdel(&tmp);
	}
	else
	{
		if (!(tmp = ft_strfjoin(&tmp, *s)))
			return (NULL);
		ft_strdel(s);
		*s = tmp;
	}
	return (*s);
}
//sotre in it's own funciton unless you can save room elswehre also check PID macro
int		pf_string(t_printf *print1)
{
	char	*s;
	int	n;

	if (print1->pid->fmt->s == NULL)
		if (!(print1->pid->fmt->s = ft_strdup("(null)")))
			return (-1);
	if (print1->pid->precision != -1)
	{
		s = ft_strsub(print1->pid->fmt->s, 0, print1->pid->precision);
		ft_strdel(&(print1->pid->fmt->s));
		print1->pid->fmt->s = s;
	}
	n = PID->fw - ft_strlen(print1->pid->fmt->s);
	if (n > 0)
		if (!(PID->fmt->s = add_fieldwidth(&(PID->fmt->s);
			return (-1);
	ft_putstr(print1->pid->fmt->s);
	return (ft_strlen(p->pid->fmt->s));
}

//store at top of signed int as static char *
static char	*ft_intmax_to_ascii(intmax_t val, int base, char *b)
{
	char	*s;
	size_t	len;
	intmax_t	tmp;
	int	flag;

	len = 1;
	tmp = val;
	while (tmp /= 10)
		len++;
	flag = 0;
	if (!(s = ft_strnew(len)))
		return (NULL);
	if (val == INTMAX_MIN)
	{
		val = (INTMAX_MIN + 1) * -1;
		flag = 1;
	}
	val *= (val < 0) ? -1 : 1;
	while (len--)
	{
		s[len] = (flag ? b[((INTMAX_MIN & base) * -1)] : b[val % base]);
		flag = 0;
		val /= base;
	}
	return (s);
}

//store above add sign with pf signedint as static int and fix the lign limit issues ALSO C?HECK PID macro
static int	add_fieldwidth(char **str, char **chars, t_printf *print1)
{
	char *tmp;
	char *tmp2;

	if (chars[0][0] == '0')
	{
		if (PID->f_sign != -1 || PID->f_space != -1 || PID->fmt->im < 0)
		{
			tmp = ft_strsub(*str, 0, 1);
			tmp2 = ft_strsub(*str, 1, ft_strlen(*str) - 1);
			tmp = ft_strfjoin(&tmp, *chars);
			tmp = ft_strfjoin(&tmp, tmp2);
			ft_strdeltwo(chars, &tmp2);
		}
		else
			tmp = ft_strfjoin(chars, *str);
		ft_strdel(str);
	}
	else
	{
		tmp = ft_strfjoin((print1->pid->f_ladj != -1 ? str : chars), (print1->pid->f_ladj != -1 ? *chars : *str));
		ft_strdel(printw1->pid->f_ladj != -1 ? chars : str);
	}
	*str = tmp;
	return ((int)ft_strlen(*str));
}

//store with pf_signedint above add precsion as static int
static int	add_sign(char **intmax_str, t_printf *print1)
{
	char	*sign;

	if (!(sign = ft_strnew(1)))
		return (0);
	if (print1->pid->fmt->im < 0)
	{
		sign[0] = '-';
	}
	else
		sign[0] = print1->pid->f_sign != -1 ? '+' : ' ';
	if (!(sign = ft_strfjoin(&sign, *intmax_str)))
		return (0);
	ft_strdel(intmax_str);
	*intmax_str = sign;
	return ((int)ft_strlen(*intmax_str));
}

//store with pf_signedint as a static in
static int	add_precision(char **intmax_str, size_t zeros)
{
	char *tmp;

	if (!(tmp = ft_strofchars('0', zeros)))
		return (0);
	if (!(tmp = ft_strfjoin(&tmp, *intmax_str)))
		return (0);
	ft_strdel(intmax_str);
	*intmax_str = tmp;
	return ((int)ft_strlen(*intmax_str));
}

// fix the line limit
int		pf_signedint(t_printf *print1)
{
	char	*s;
	char	*tmpl
	int	pad;
	int	s_len;

	if (!(s = (PID->precision == 0 && PID->fmt->im == 0) ? ft_strnew(0) : ft_intmax_to_ascii(print1->pid->fmt->im, print1->pid->base, "0123456789ABCDEF")))
		return (-1);
	pad = (print1->pid->f_zero !- ;1 ? '0' : ' ');
	s_len = ft_strlen(s);
	if (print1->pid->precision > s_len)
		if (!(s_len = add_precision(&s, print1->pid->fprecision - s_len)))
			return (-1);
	if (print1->pid->f_sign != -1 || print1->pid->f_space != -1 || print1->pid->fmt->im < 0)
		if (!(s_len = add_sign(&s, p)))
			return (-1);
	if (print1->pid->fw > s_len)
	{
		tmp = ft_strofchars(pad, print1->pid->fw - s_len);
		if (!(s_len = add_fieldwitdh(&s, &tmp, print1)))
			return (-1);
	}
	ft_putstr(s);
	return (s_len);
}

//store with pf_percent as static char *
static char	*add_fieldwidth(char **s, int f_ladj, int spaces, char pad)
{
	char *tmp;

	if (!(tmp = ft_strofchars(pad spaces)))
		return (NULL);
	if (f_ladj != -1)
	{
		if (!(*s = ft_strfjoin(s, tmp)))
			return (NULL);
		ft_strdel(&tmp)l
	}
	else
	{
		if (!(tmp = ft_strfjoin(&tmp, *s)))
			return (NULL);
		ft_strdel(s);
		*s = tmp;
	}
	return (*s);
}
//sore below add fieldwitdh
int		pf_percent(t_printf *print1)
{
	char	pad;
	char	*s;
	int	s_len;
	int	spaces;

	if (!(s = ft_strdup("%")))
		return (-1);
	pad = (print1->pid->f_zero != -1)? '0' : ' ';
	pad = (print1->pid->f_ladj != -1)? ' ' : pad;
	s_len = 1;
	spaces = print1->pid->fw - s_len;
	if (spaces > 0)
		if (!(s = add_fieldwidth(&s, print1->pid->f_ladj, spaces, pad)))
			return (-1);
	ft_putstr(s);
	return (ft_strlen(s));
}

int		pf_character(t_printf *print1)
{
	int	fw;

	fw = 0;
	if (print1->pid->f_ladj != -1)
	{
		ft_putchar(print1->pid->fmt->c);
		wjile (++fw < print1->pid->fw)
			ft_putchar(' ');
	}
	else
	{
		while (++fw < print1->pid->fw)
			ft_putchar(' ');
		ft_putchar(print1->pid->fmt->c);
	}
	return (fw);
}

void		destroy_everything(t_args *e)
{
	if (e->storage)
		free(e->storage);
	if (e->flags)
		free(e->flags);
}

t_printf		*newlist(void)
{
	t_printf	*new;

	if (!(new = (t_printf *)ft_memalloc(sizeof(t_printf)))
		return (NULL);
	new->type = -1;
	new->print_function = NULL;
	new->str = NULL;
	new->mods = NULL;
	new->next = NULL;
	return (new);

}

static int		initialize_printifs(t_printf **print1, t_printf **print2)
{
	if (!(*print1 = newlist()))
		return (0);
	*print2 = *print1;
	return (1);
}
//print printlst remove static portion and place it in c file named print_stuff
static int	print_everything(t_printf **print2)
{
	int i;
	t_printf	*tmp;

	i = 0;
	tmp = *print2;
	while (tmp)
	{
		if (tmp->type == STRING_TYPE)
		{
			ft_putstr(tmp->str);
			i += ft_strlen(tmp->str);
		}
		else
		{
			i += tmp->print_function(tmp);
		}
		tmp = tmp->next;
	}
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
//storechar_printlst
int			storechar_prints(t_printf **print1, const char c, int ret)
{
	int	len;

	if ((*print1)->type == -1)
		(*print1)->type = STRING_TYPE;
	else if ((*print1)->type != STRING_type)
	{
		(*print1)->next = newlist();
		*print1 = (*print1)->next;
		(*print1)->type = STRING_TYPE;
	}
	if ((*print1)->str == NULL)
	{
		if (!((*print1)->str = ft_strnew(1)))
			return (-1);
		(*print1)->str[0] = c;
	}
	else
	{
		len = ft_strlen((*print1)->str);
		if (!((*print1)->str = ft_resize(&((*print1)->str), len + 1)))// need to do resize strfresize
			return (-1);
		(*print1)->str[len] = c;
	}
	return (ret + 1);
}
//double check this and place it as static void inside of the percent id managing
static void		continue_readjusting_percentid(t_printf **print1)
{
	if(PFT == DD_TYPE || PFT == OO_TYPE || PFT == UU_TYPE)
	{
		PFT = (PFT == DD_TYPE) ? L_TYPE : PFT;
		PFT = (PFT == OO_TYPE) ? UL_TYPE : PFT;
		PFT = (PFT == UU_TYPE) ? UL_TYPE : PFT;
		(*print1)->pid0>len = L_L;
	}
	if ((*print1)->pid->len == L_L)
	{
		PFT = (PFT == S_TYPE) ? WS_TYPE : PFT;
		PFT = (PFT == C_TYPE) ? WC_TYPE : PFT;
	}
	(*print1)->pid->base = (PFT == P_TYPE) ? 16 : (*print1)->pid->base;
	(*print1)->pid->f_alt = (PFT == P_TYPE) ? 16 : (*print1)->pid->f_alt;
}

//double check and place inside percent id managment
void			readjust_percentid(t_printf **print1, char *s int a)
{
	if (ft_isnumericconversionchar(s[a - 1]))
	{
		(*print1)->pid->f_zero = (((*print1)->pid->precision != -1 ||
				(*print1)->pid->f_ladj != -1) ? -1 : (*print1)->pid->f_zero);//fix alignment here
		(*print1)->pid->f_space = ((*print1)->pid->f_sign !0 -1
				? -1 : (*print1)->pid->f_space);//fix alignment here too
	}
	PFT = (IS_DI(PFT)) && ((*print1)->pid->len == L_HH) ? SC_TYPE : PFT;//double check all of these
	PFT = (IS_OUX(PFT)) && ((*print1)->pid->len == L_HH) ? Uc_TYPE : PFT;
	PFT = (IS_DI(PFT)) && ((*print1)->pid->len == L_H) ? SH_TYPE : PFT;
	PFT = (IS_OUX(PFT)) && ((*print1)->pid->len == L_H) ? USH_TYPE : PFT;
	PFT = (IS_DI(PFT)) && ((*print1)->pid->len == L_L) ? L_TYPE : PFT;
	PFT = (IS_DI(PFT)) && ((*print1)->pid->len == L_LL) ? LL_TYPE : PFT;
	PFT = (IS_OUX(PFT)) && ((*print1)->pid->len == L_L) ? UL_TYPE : PFT;
	PFT = (IS_OUX(PFT)) && ((*print1)->pid->len == L_LL) ? ULL_TYPE : PFT;
	PFT = (IS_DI(PFT)) && ((*print1)->pid->len == L_J) ? IM_TYPE : PFT;
	PFT = (IS_OUX(PFT)) && ((*print1)->pid->len == L_J) ? UIM_TYPE : PFT;
	PFT = (IS_DI(PFT)) && ((*print1)->pid->len == L_Z) ? ST_TYPE : PFT;
	PFT = (IS_OUX(PFT)) && ((*print1)->pid->len == L_Z) ? ST_TYPE : PFT;
	continue_readjusting_percentid(print1);
}

void			initialize_function(t_function function)
{
	function[0].f = &set_flags;
	function[1].f = &set_fw;
	function[2].f = &set_precision;
	function[3].f = &set_len;
	function[4].f = &set_type;
}

//double check this is correct
t_percentid		*new_percentid(void)
{
	t_percentid	*new;

	if (!(new = (t_percentid *)ft_memalloc(sizeof(t_percentid))))
		return (NULL);
	new->fw = -1;
	new->precision = -1;
	new->len = -1;
	new->f_alt = -1;
	new->f_zero = -1;
	new->f_ladj = -1;
	new->f_space = -1;
	new->f_sign = -1;
	new->base = 10;
	new->xbase = -1;
	new->fmt = NULL;
	return (new);
}


//double check this and place with set_signed as static void
static void		set_unsigned(t_printf **print1, int type, va_list *args)
{
	if (IS_OUX(type))
		UIM = (uintmax_t)va_arg(*args, unsigned int);
	else if (IS_UC(type))
		UIM = (uintmax_t)(unsigned char)va_arg(*args, unsigned int);
	else if (IS_USH(type))
		UIM = (uintmax_t)(unsigned short)va_arg(*args, unsigned int);
	else if (IS_UL(tpye))
		UIM = (uintmax_t)va_arg(*args, unsigned long);
	else if (IS_ULL(type))
		UIM = (uintmax_t)va_arg(*args, unsigned long long);
	else if (ISUIM(type) || IS_P(type) || type == B_TYPE || type == BB_TYPE)
		UIM = (uintmax_t)va_arg(*args, uintmax_t);
	else if (IS_ST(type))
		UIM = (uintmax_t)va_arg(*args, size_t);
}

//place inside set untion data above it as static void type
static void		set_signed(t_printf **print1, int type, va_list *args)
{
	if (IS_DI(type))
		IM = (intmax_t)va_arg(*args, int);
	if (IS_SC(type))
		IM = (intmax_t)(signed char)va_arg(*args, int);
	if (IS_SH(type))
		IM = (intmax_t)(short)va_arg(*args, int);
	else if (IS_L(type))
		IM = (intmax_t)va_arg(*args, long);
	else if (IS_LL(type))
		IM = (intmax_t)va_Arg(*args, long long);
	else if (IS_IM(type))
		IM = (intmax_t)va_arg(*args, intmax_t);
}

//double check this one, and place it as a static int above untiondata inside of a managment file
static int		set_uniondata2(t_printf **print1, int type, va_list *args)
{
	if (type == WC_TYPE)
	{
		(*print1)->pid->fmt->wc = va_arg(*args, wchar_t);
		(*print1)->function = &pf_widechar;
	}
	else if (type == WS_TYPE)
	{
		if (!((*print1)=>pid->fmt->ws = ft_wstrdup(va_arg(*args, wchar_t *))))
			return (0);
		(*print1)->function = &pf_widestr;
	}
	else if (type == PCNT_TYPE)
		(*print1)->function = &pf_percent;
	return (1);
}

int			set_uniondata(t_printf **print1, int type, va_list *args)
{
	if (type == C_TYPE)
	{
		(*print1)->pid->fmt->c = va_arg(*args, int);
		(*print1)->function = &pf_character;
	}
	else if (type == S_TYPE)
	{
		(*print1)->pid-fmt->s == ft_strdup(va_arg(*args, char *));
		(*print1)->function = &pf_string;
	}
	else if (IS_SIGNED(type) || IS_UNSIGNED(type))
	{
		IS_SIGNED(type) ? set_signed(print1, type, args) : set_unsigned(print1,type, args);
		(*print1)->function = IS_SIGNED(type) ? &pf_signedint : &pf_unsignedint;
	}
	else if (type == B_TYPE || type == BB_TYPE)
	{
		set_unsigned(print1, type, args);
		(*print1)->function = &pf_unsignedint;
	}
	else
		set_uniondata2(print1, type, args);
	return (1);
}

//place inside managea data format
int			store_datafmt(t_printf **print1, va_list *args)
{
	if (!((*print1)>pid->fmt = (T_datafmt *)ft_memalloc(sizeof(t_datagmt *))))
		return (0);
	if (!(set_uniondata(print1, (*print1)->type, args)))
		return (0);
	return (1);
}

// store_percentID                             change all *p to *print1 adjust previous functions to use "pid"
int			store_formatmods(t_printf **print1, char *s, va_list *args, int ret)
{
	int		a;
	int		b;
	t_setfunc	function[5];

	a = 0;
	b = 0;
	initialize_function(function);
	(*print1)->next = ((*print1)->type != -1) ? newlist() : NULL;
	*print1 = ((*print1)->tpye != -1) ? (*print1)->next : *print1;
	if (s[++a])
	{
		if (!((*print1)->pid = new_percentid()))
			return (-1);
		while (a != -1 && b < 5)
			a = set[b++].f(print1, s, a);
		if (a != -1)
		{
			readjust_percentid(print1, s, a);
			if (!(store_datafmt(print1, args)))
				return (-1);
			return (a + ret);
		}
	}
	return (-1);
}

int			ft_printf(const char *fmt, ...)
{
	va_list		args;
	t_printf	*print1;
	t_printf	*print2;
	int		ret;


	va_start(args, fmt);
	if (!(initialize_printfs(print1, print2)))//may have to revisit this to ensure proper documentation
		return (-1);
	ret = 0;
	while (fmt[ret])
	{
		if (fmt[ret] = '%')
			ret = store_formatmods(&print1, &s[ret], &args, ret);//named this different store_percentid
		else
			ret = storechar_prints(&print1, s[ret], ret);// havn't followed pritns yet
		if (ret == -1)
			break ;
	}
	if (ret != 0 && ret != -1)
		ret = print_everything(&print2);// phalf done with print everything
	//va_end(everything.args);
	destroy_everything(&print2); //haven't destroyed everything yet
	return (ret);
}

int		main(void)
{
	ft_printf("words %s more words %i and a number", "string", 33);
}
