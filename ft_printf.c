/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 13:07:52 by dborysen          #+#    #+#             */
/*   Updated: 2017/12/26 13:07:53 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	ft_char_place(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

size_t ft_count_flags(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != 's' && s[i] != 'S' && s[i] != 'p' && s[i] != 'd' && 
		s[i] != 'D' && s[i] != 'i' && s[i] != 'o' && s[i] != 'O' && 
		s[i] != 'u' && s[i] != 'U' && s[i] != 'x' && s[i] != 'X' && 
		s[i] != 'c' && s[i] != 'C')
		i++;
	return(i + 1);
}

char ft_corrent_type(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != 's' && s[i] != 'S' && s[i] != 'p' && s[i] != 'd' && 
		s[i] != 'D' && s[i] != 'i' && s[i] != 'o' && s[i] != 'O' && 
		s[i] != 'u' && s[i] != 'U' && s[i] != 'x' && s[i] != 'X' && 
		s[i] != 'c' && s[i] != 'C')
		i++;
	return(s[i]);
}

char ft_priority_flag(char *s)
{
	if (ft_strchr(s, 'z'))
		return ('z');
	else if (ft_strchr(s, 'j'))
		return ('j');
	else if (ft_strstr(s, "ll"))
		return ('L');
	else if (ft_strchr(s, 'l'))
		return ('l');
	else if (ft_strstr(s, "hh"))
		return ('H');
	else if (ft_strchr(s, 'h'))
		return ('h');
	return (0);
}

char ft_char_priority_flag(char *s)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if(s[i] == 'l')
			count++;
		i++;
	}
	if (count % 2 != 0)
		return ('l');
	return (0);
}

void ft_zero_search(char *s, t_flags *flags)
{
	int i;
	int m;

	i = 0;
	m = 0;
	while (s[i])
	{
		if (s[i] == '0' && (s[i - 1] < '0' || s[i - 1] > '9'))
		{
			m++;
			break ;
		}
		i++;
	}
	if (m > 0)
		flags->zero = '0';
	i = 0;
}

void ft_width_search(char *s, t_flags *flags)
{
	size_t i;
	int k;
	int m;
	char *t;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i - 1] != '.' && (s[i] >= '1' && s[i] <= '9'))
			break;
		i++;
	}
	if (i < ft_strlen(s))
	{
		m = i;
		while (s[m] >= '0' && s[m] <= '9')
		{
			k++;
			m++;
		}
		t = ft_strsub(s, i, k);
		flags->width = ft_atoi(t);
		ft_strdel(&t);
	}
}

void ft_precision_search(char *s, t_flags *flags)
{
	int i;
	int k;
	int m;
	char *t;

	k = 0;
	i = 0;
	while (s[i] != '.' && s[i])
		i++;
	i++;
	m = i;
	while (s[m] >= '0' && s[m] <= '9')
	{
		m++;
		k++;
	}
	t = ft_strsub(s, i, k);
	flags->precision = ft_atoi(t);
	ft_strdel(&t);
}

// void ft_star_search(char *s, t_flags *flags)
// {


// }

void ft_is_a_flag(char *s, t_flags *flags)
{
	int i;
	int k;

	k = 0;
	i = 0;
	if (ft_strchr(s, '+'))
		flags->plus = '+';
	if (ft_strchr(s, '-'))
		flags->minus = '-';
	if (ft_strchr(s, '#'))
		flags->hash = '#';
	if (ft_strchr(s, ' '))
		flags->space = ' ';
	if (ft_strchr(s, '*'))
		flags->star = '*';
	flags->type = ft_corrent_type(s);
	if (ft_strchr(s, '.'))
		ft_precision_search(s, flags);
	ft_width_search(s, flags);
	ft_zero_search(s, flags);
	if (flags->type != 'c' && flags->type != 's')
		flags->size_flag = ft_priority_flag(s);
	else 
		flags->size_flag = ft_char_priority_flag(s);
}

int ft_count_digit(long long n)
{
	int i;

	i = 0;
	while ((n / 10))
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////

void ft_output_C(t_flags *flags, long long argptr)
{
	(void)flags;
	ft_print_unicode((int)argptr);
}

void ft_output_S(t_flags *flags, long long argptr)
{
	int *m;
	int k;

	k = 0;
	(void)flags;
	m = (int*)(argptr);
	while (m[k])
		ft_print_unicode(m[k++]);
}

void ft_output_c(t_flags *flags, long long argptr)
{
	if (flags->size_flag == 'l')
		ft_print_unicode((int)argptr);
	else
		flags->bnum += ft_putchar((unsigned char)(argptr));
}

void ft_output_D(t_flags *flags, long long argptr)
{
	(void)flags;
	ft_putlonglong(argptr);
}

void ft_output_O(t_flags *flags, long long argptr)
{
	char *temp;

	(void)flags;
	if (flags->hash == '#')
	{
		ft_putchar('0');
		flags->bnum++;
	}
	temp = ft_itoa_base((unsigned long)argptr, 8);
	ft_putstr(temp);
	ft_strdel(&temp);
}

void ft_output_X(t_flags *flags, long long argptr)
{
	char *temp;

	if (flags->hash == '#')
	{
		ft_putstr("0X");
		flags->bnum = flags->bnum + 2;
	}
	if (flags->size_flag == 'H')
		temp = ft_itoa_base((unsigned char)argptr, 16);
	else if (flags->size_flag == 'h')
		temp = ft_itoa_base((unsigned short int)argptr, 16);
	else if (flags->size_flag == 'z')
		temp = ft_itoa_base((size_t)argptr, 16);
	else if (flags->size_flag == 'j')
		temp = ft_itoa_base((uintmax_t)argptr, 16);
	else if (flags->size_flag == 'l')
		temp = ft_itoa_base((unsigned long)argptr, 16);
	else if (flags->size_flag == 'L')
		temp = ft_itoa_base((unsigned long long)argptr, 16);
	else 
		temp = ft_itoa_base((unsigned int)argptr, 16);
	flags->bnum += ft_putstr(temp);
	ft_strdel(&temp);
}

void ft_output_U(t_flags *flags, unsigned long long argptr)
{
	if (flags->size_flag == 'H')
		flags->bnum += ft_putllu((unsigned char)argptr);
	else if (flags->size_flag == 'h')
		flags->bnum += ft_putllu((unsigned short int)argptr);
	else if (flags->size_flag == 'z')
		flags->bnum += ft_putllu((size_t)argptr);
	else if (flags->size_flag == 'j')
		flags->bnum += ft_putllu((uintmax_t)argptr);
	else
		flags->bnum += ft_putllu(argptr);
}

void ft_output_p(t_flags *flags, long long argptr)
{
	char *temp;

	(void)flags;
	flags->bnum = flags->bnum + 2;
	temp = ft_lowstr(ft_itoa_base(argptr, 16));
	ft_putstr("0x");
	flags->bnum += ft_putstr(temp);
	ft_strdel(&temp);
}

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////

 void  ft_which_output(char type, void (**ft_output)(t_flags *, long long))
 {
 	if (type == 's')
		*ft_output = &ft_output_s;
	else if (type == 'S')
		*ft_output = &ft_output_S;
	else if (type == 'p')
		*ft_output = &ft_output_p;
	else if (type == 'D')
		*ft_output = &ft_output_D;
	else if (type == 'i' || type == 'd')
		*ft_output = &ft_output_d;
	else if (type == 'o')
		*ft_output = &ft_output_o;
	else if (type == 'O')
		*ft_output = &ft_output_O;
	else if (type == 'x')
		*ft_output = &ft_output_x;
	else if (type == 'X')
		*ft_output = &ft_output_X;
	else if (type == 'c')
		*ft_output = &ft_output_c;
	else if (type == 'C')
		*ft_output = &ft_output_C;
 }

void  ft_which_output_u(char type, void (**ft_outputu)(t_flags *, unsigned long long))
{
	if (type == 'u')
		*ft_outputu = &ft_output_u;
	else if (type == 'U')
		*ft_outputu = &ft_output_U;
}

int ft_printf(const char *s, ...) 
{
	int		i;
	int		ret;
	int		temp;
	char	*tmp_str;
	void	(*ft_output)(t_flags*, long long);
	void	(*ft_outputu)(t_flags*, unsigned long long);
	t_flags	*flags;
	va_list	argptr;

	i = 0;
	ret = 0;
	flags = (t_flags*)malloc(sizeof(t_flags));
	flags->precision = 0;
	flags->width = 0;
	flags->bnum = 0;
	va_start(argptr, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] != '%')
		{
			tmp_str = ft_strsub(s, i, ft_count_flags(s + i));
			ft_is_a_flag(tmp_str, flags);
			if (MB_CUR_MAX == 1 && flags->type == 'C')
				flags->type = 'c';
			// printf("flags->size_flag - [%c]\n", flags->size_flag);
			// printf("flags->type - [%c]\n", flags->type);
			// printf("flags->plus - [%c]\n", flags->plus);
			// printf("flags->star - [%c]\n", flags->star);
			// printf("flags->minus - [%c]\n", flags->minus);
			// printf("flags->zero - [%c]\n", flags->zero);
			// printf("flags->hash - [%c]\n", flags->hash);
			// printf("flags->space - [%c]\n", flags->space);
			// printf("flags->precision - [%d]\n", flags->precision);
			// printf("flags->width - [%d]\n", flags->width);
			ft_strdel(&tmp_str);
			if (flags->star == '*')
			{
				temp = va_arg(argptr, unsigned long long);
				if (temp)
					flags->width = temp;
			}
			if (flags->type == 'u' || flags->type == 'U')
			{
				ft_which_output_u(flags->type, &ft_outputu);
				ft_outputu(flags, va_arg(argptr, unsigned long long));
			}
			else
			{
				ft_which_output(flags->type, &ft_output);
				ft_output(flags, va_arg(argptr, long long int));
			}
			i = i + ft_count_flags(s + i);
		}
		else if (s[i] == '%' && s[i + 1] == '%')
		{
			flags->bnum += ft_putchar(s[i]);
			i = i + 2;
		}
		else
			flags->bnum += ft_putchar(s[i++]);
	}
	va_end(argptr);
	free(flags);
	// printf("\nflags->bnum - [%u]\n", flags->bnum);
	return (flags->bnum);
}

