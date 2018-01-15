/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 10:17:06 by dborysen          #+#    #+#             */
/*   Updated: 2017/12/28 10:17:08 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void ft_putfloat(float n)
{
	float temp;
	// unsigned long int dec;
	int intpart;
	int dec;
	int i;

	i = 0;
	intpart = 0;
	temp = (signed long int)n;
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	ft_putnbr(temp);
	while (temp / 10 >= 1)
	{
		intpart = intpart * 10 + temp % 10;
		temp = temp / 10;
		i++;
	}
	printf("\ni  = [%d]\n", i);
	// printf("\ntemp = [%f]\n", temp);
	printf("intpatr - [%d]\n", intpart);
}

int main(int argc, char const *argv[])
{
	ft_putfloat(234.123456);
	return (0);
}
