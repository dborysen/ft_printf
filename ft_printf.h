/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:31:21 by dborysen          #+#    #+#             */
/*   Updated: 2018/01/11 16:31:25 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <locale.h>
# include <stdarg.h>
# include <stdint.h>
# include "libft/includes/libft.h"

typedef struct	s_flags
{
	char	size_flag;
	char	type;
	char	plus;
	char	minus;
	char	zero;
	char	hash;
	char	space;
	int		precision;
	int		width;
}				t_flags;

void			ft_output_d(t_flags *flags, long long argptr);
int				ft_count_digit(long long n);

#endif