/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:07:54 by dborysen          #+#    #+#             */
/*   Updated: 2018/01/17 16:07:58 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int count_dig(int n, int base)
{
	int i;

	i = 0;
	while (n / base)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char	*ft_itoa_base_pf(unsigned long long v, int base, t_flags *flags)
{
	char	*baseline;
	char	*result;
	int		i;
	int		tmp;

	i = 0;
	tmp = v;
	baseline = ft_strdup("0123456789ABCDEF");
	i = count_dig(tmp, base);
	flags->bnum = i + 3;
	if ((result = (char*)malloc(sizeof(char) * (i + 2))) == 0)
		return (NULL);
	i = 0;
	while (v / base > 0)
	{
		(v % base < 10) ? (result[i++] = v % base + 48) :
		(result[i++] = baseline[v % base]);
		v = v / base;
	}
	(v < 10) ? result[i++] = (v % base + 48) :
	(result[i++] = baseline[v]);
	result[i] = '\0';
	ft_reverse(result);
	free(baseline);
	return (result);
}