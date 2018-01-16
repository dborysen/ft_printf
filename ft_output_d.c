/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:21:49 by dborysen          #+#    #+#             */
/*   Updated: 2018/01/11 16:21:50 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void right_alignment(t_flags *flags, long long argptr)
{
	int n;
	int temp;
	int temp_width;
	int zero_num;

	temp = 0;
	temp_width = 0;
	zero_num = 0;
	n = 0;
	//flags->bnum += ft_putlonglong(argptr);
	// printf("%lld\n", argptr);
	if (flags->precision != 0)
		zero_num = flags->precision - ft_count_digit((int)argptr);
	if (argptr < 0)
		temp = 1;
	if (flags->plus == '+' || (int)argptr < 0 || flags->space == ' ')
	{
		flags->width = flags->width - 1;
		if (flags->zero == '0' && (int)argptr < 0)
		{
			argptr = -argptr;
			flags->bnum += ft_putchar('-');
		}
		else if (flags->zero == '0' && flags->plus == '+')
			flags->bnum += ft_putchar('+');
		else if (flags->zero == '0' && flags->space == ' ')
			flags->bnum += ft_putchar(' ');
		else if (flags->zero != '0' && (int)argptr < 0)
			argptr = -argptr;
		else if (flags->zero != '0' && flags->space == ' ' && flags->plus != '+')
			flags->bnum += ft_putchar(' ');
	}
	while (n < (flags->width - ft_count_digit(argptr) - zero_num))
	{
		if (flags->zero != '0' || flags->precision != 0)
			flags->bnum += ft_putchar(' ');
		else if (flags->precision == 0)
			flags->bnum += ft_putchar('0');
		n++;
	}
	n = 0;
	if (flags->zero != '0' && flags->plus == '+' && temp != 1)
		flags->bnum += ft_putchar('+');
	if (flags->zero != '0' && temp == 1)
		flags->bnum += ft_putchar('-');
	if (flags->precision != 0)
	{
		while (n++ < zero_num)
			flags->bnum += ft_putchar('0');
		n = 0;
		flags->bnum += ft_putlonglong(argptr);
	}
	else 
		flags->bnum += ft_putlonglong(argptr);
	// printf("num of bytes - [%d]\n", ft_putlonglong(argptr));
	// printf("argptr - [%lld]\n", argptr);
}

void left_alignment(t_flags *flags, long long argptr)
{
	int n;
	int zero_num;
	int neg;

	n = 0;
	neg = 0;
	if (argptr < 0)
		neg = 1;
	zero_num = 0;
	if (flags->precision != 0)
	{
		zero_num = flags->precision - ft_count_digit((int)argptr);
		if (flags->plus == '+' && (int)argptr > 0)
			flags->bnum += ft_putchar('+');
		else if ((int)argptr < 0)
		{
			flags->bnum += ft_putchar('-');
			argptr = - argptr;
		}
		else if (flags->space == ' ')
			flags->bnum += ft_putchar(' ');
		while (n++ < zero_num)
			flags->bnum += ft_putchar('0');
		flags->bnum += ft_putlonglong(argptr);
		n = 0;
		if (neg == 1 || flags->plus == '+' || flags->space ==' ')
			while (n++ < (flags->width - flags->precision - 1))
				flags->bnum += ft_putchar(' ');
	}
	else
	{
		if (neg == 1|| flags->plus == '+' || flags->space == ' ')
		{
			flags->width = flags->width - 1;
		}		
		if (flags->plus == '+' && (int)argptr > 0)
			flags->bnum += ft_putchar('+');
		else if (flags->space == ' ' && (int)argptr >= 0)
			flags->bnum += ft_putchar(' ');
		flags->bnum += ft_putlonglong(argptr);
		// printf("space num - [%d]\n", flags->width);
		while (n < (flags->width - ft_count_digit(argptr)))
		{
			flags->bnum += ft_putchar(' ');
			n++;
		}
	}
}

void ft_output_d(t_flags *flags, long long argptr)
{
	int n;
	int temp;

	n = 0;
	temp = 0;
	if (flags->size_flag == 'H')
		(flags->minus == '-') ? left_alignment(flags, (signed char)argptr) : 
		right_alignment(flags, (signed char)argptr);
	else if (flags->size_flag == 'h')
		(flags->minus == '-') ? left_alignment(flags, (short int)argptr) :
		right_alignment(flags, (short int)argptr);
	else if (flags->size_flag == 'j')
		(flags->minus == '-') ?	left_alignment(flags, (intmax_t)argptr) :
		right_alignment(flags, (intmax_t)argptr);
	else if (flags->size_flag == 'l')
		(flags->minus == '-') ? left_alignment(flags, (long int)argptr) :
		right_alignment(flags, (long int)argptr);
	else if (flags->size_flag == 'z')
		(flags->minus == '-') ? left_alignment(flags, (size_t)argptr) :
		right_alignment(flags, (size_t)argptr);
	else
		(flags->minus == '-') ? left_alignment(flags, (int)argptr) : 
		right_alignment(flags, (int)argptr);
}
