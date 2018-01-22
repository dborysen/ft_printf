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

void	ft_which_output(char type, void (**ft_output)(t_flags *, long long))
{
	if (type == 's')
		*ft_output = &ft_output_s;
	else if (type == 'S')
		*ft_output = &ft_output_sbig;
	else if (type == 'p')
		*ft_output = &ft_output_p;
	else if (type == 'D')
		*ft_output = &ft_output_dbig;
	else if (type == 'i' || type == 'd')
		*ft_output = &ft_output_d;
	else if (type == 'o')
		*ft_output = &ft_output_o;
	else if (type == 'O')
		*ft_output = &ft_output_obig;
	else if (type == 'x')
		*ft_output = &ft_output_x;
	else if (type == 'X')
		*ft_output = &ft_output_xbig;
	else if (type == 'c')
		*ft_output = &ft_output_c;
	else if (type == 'C')
		*ft_output = &ft_output_cbig;
}

void	ft_which_output_u(char type, void (**ft_outputu)
	(t_flags *, unsigned long long))
{
	if (type == 'u')
		*ft_outputu = &ft_output_u;
	else if (type == 'U')
		*ft_outputu = &ft_output_ubig;
	else if (type == 'b')
		*ft_outputu = &ft_output_b;
}

int		ft_printf(const char *s, ...)
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
			if (ft_count_flags(s + i) == 0)
				return (-1);
			tmp_str = ft_strsub(s, i, ft_count_flags(s + i));
			ft_is_a_flag(tmp_str, flags);
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
			if (MB_CUR_MAX == 1 && flags->type == 'C')
				flags->type = 'c';
			ft_strdel(&tmp_str);
			if (flags->star == '*')
			{
				temp = va_arg(argptr, unsigned long long);
				if (temp)
					flags->width = temp;
			}
			if (flags->type == 'u' || flags->type == 'U' || flags->type == 'b')
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
	return (flags->bnum);
}
