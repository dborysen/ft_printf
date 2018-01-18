/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 11:21:16 by dborysen          #+#    #+#             */
/*   Updated: 2018/01/18 11:21:20 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_output_s(t_flags *flags, long long argptr)
{
	int *m;
	int k;

	k = 0;
	m = 0;
	if (flags->size_flag == 'l')
	{
		m = (int*)(argptr);
		while (m[k])
			ft_print_unicode(m[k++]);
	}
	else
	{
		if (flags->minus == '-')
		{
			if (flags->precision != 0)
				while (k < flags->precision)
					(flags->bnum += ft_putchar(((char*)argptr)[k++]));
			else
			{
				flags->bnum += ft_putstr((char*)argptr);
			}
			if ((unsigned long)flags->width > ft_strlen((char*)argptr) - flags->precision)
				while ((unsigned long)flags->width-- > ft_strlen((char*)argptr) - flags->precision)
					flags->bnum += ft_putchar(' ');
		}
		else
		{
			if ((unsigned long)flags->width > ft_strlen((char*)argptr) - flags->precision)
				while ((unsigned long)flags->width-- > ft_strlen((char*)argptr) - flags->precision)
					(flags->zero == '0') ? (flags->bnum += ft_putchar('0')) :
						(flags->bnum += ft_putchar(' '));
			if (flags->precision != 0)
				while (k < flags->precision)
					flags->bnum += ft_putchar(((char*)argptr)[k++]);
			else
				(flags->bnum += ft_putstr((char*)argptr));
		}
	}
}