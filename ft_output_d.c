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
	//ft_putlonglong(argptr);
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
			ft_putchar('-');
		}
		else if (flags->zero == '0' && flags->plus == '+')
			ft_putchar('+');
		else if (flags->zero == '0' && flags->space == ' ')
			ft_putchar(' ');
		else if (flags->zero != '0' && (int)argptr < 0)
			argptr = -argptr;
	}
	while (n < (flags->width - ft_count_digit(argptr) - zero_num))
	{
		if (flags->zero != '0')
			ft_putchar(' ');
		else
			ft_putchar('0');
		n++;
	}
	n = 0;
	if (flags->zero != '0' && flags->plus == '+' && temp != 1)
		ft_putchar('+');
	if (flags->zero != '0' && temp == 1)
		ft_putchar('-');
	if (flags->precision != 0)
	{
		while (n++ < zero_num)
			ft_putchar('0');
		n = 0;
		ft_putlonglong(argptr);
	}
	else 
		ft_putlonglong(argptr);
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
			ft_putchar('+');
		else if ((int)argptr < 0)
		{
			ft_putchar('-');
			argptr = - argptr;
		}
		else if (flags->space == ' ')
			ft_putchar(' ');
		while (n++ < zero_num)
			ft_putchar('0');
		ft_putlonglong(argptr);
		n = 0;
		if (neg == 1 || flags->plus == '+' || flags->space ==' ')
			while (n++ < (flags->width - flags->precision - 1))
				ft_putchar(' ');
	}
	else
	{
		if (neg == 1|| flags->plus == '+' || flags->space == ' ')
		{
			flags->width = flags->width - 1;
			// printf("im here!");
		}
			
		if (flags->plus == '+' && (int)argptr > 0)
			ft_putchar('+');
		else if (flags->space == ' ' && (int)argptr >= 0)
			ft_putchar(' ');
		ft_putlonglong(argptr);
		// printf("space num - [%d]\n", flags->width);
		while (n < (flags->width - ft_count_digit(argptr)))
		{
			ft_putchar(' ');
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
	{
		if (flags->minus == '-')
			left_alignment(flags, (signed char)argptr);
		else
			right_alignment(flags, (signed char)argptr);
	}
	else if (flags->size_flag == 'h')
	{
		if (flags->minus == '-')
			left_alignment(flags, (short int)argptr);
		else
			right_alignment(flags, (short int)argptr);
	}
	else if (flags->size_flag == 'j')
	{
		if (flags->minus == '-')
			left_alignment(flags, (intmax_t)argptr);
		else
			right_alignment(flags, (intmax_t)argptr);
	}
	else if (flags->size_flag == 'l')
	{
		if (flags->minus == '-')
			left_alignment(flags, (long int)argptr);
		else
			right_alignment(flags, (long int)argptr);
	}
	else if (flags->size_flag == 'z')
	{
		if (flags->minus == '-')
			left_alignment(flags, (size_t)argptr);
		else
			right_alignment(flags, (size_t)argptr);
	}
	else
	{
		if (flags->minus == '-')
			left_alignment(flags, (int)argptr);
		else
			right_alignment(flags, (int)argptr);
	}
}
