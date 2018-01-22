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
	t_phelp *help;
	t_flags	*flags;
	va_list	argptr;

	help = (t_phelp*)malloc(sizeof(t_phelp));
	flags = (t_flags*)malloc(sizeof(t_flags));
	help->i = 0;
	flags->precision = 0;
	flags->width = 0;
	flags->bnum = 0;
	va_start(argptr, s);
	while (s[help->i])
	{
		if (s[help->i] == '%' && s[help->i + 1] != '%')
		{
			if (ft_count_flags(s + help->i) == 0)
			{
				free(flags);
				free(help);
				return (-1);
			}
			help->tmp_str = ft_strsub(s, help->i, ft_count_flags(s + help->i));
			ft_is_a_flag(help->tmp_str, flags);
			ft_strdel(&help->tmp_str);
			if (MB_CUR_MAX == 1 && flags->type == 'C')
				flags->type = 'c';
			if (flags->star == '*')
			{
				help->temp = va_arg(argptr, unsigned long long);
				if (help->temp)
					flags->width = help->temp;
			}
			if (flags->type == 'u' || flags->type == 'U' || flags->type == 'b')
			{
				ft_which_output_u(flags->type, &help->ft_outputu);
				help->ft_outputu(flags, va_arg(argptr, unsigned long long));
			}
			else
			{
				ft_which_output(flags->type, &help->ft_output);
				help->ft_output(flags, va_arg(argptr, long long int));
			}
			help->i = help->i + ft_count_flags(s + help->i);
		}
		else if (s[help->i] == '%' && s[help->i + 1] == '%')
		{
			flags->bnum += ft_putchar(s[help->i]);
			help->i = help->i + 2;
		}
		else
			flags->bnum += ft_putchar(s[help->i++]);
	}
	va_end(argptr);
	free(help);
	free(flags);
	return (flags->bnum);
}

