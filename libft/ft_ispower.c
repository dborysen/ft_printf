/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ispower.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:57:50 by dborysen          #+#    #+#             */
/*   Updated: 2017/11/26 11:43:11 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_ispower(int x)
{
	return (x & x - 1) == 0;
}
