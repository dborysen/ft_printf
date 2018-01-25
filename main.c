/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:52:28 by dborysen          #+#    #+#             */
/*   Updated: 2018/01/16 16:52:30 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>
#include <stdio.h>


int main(void)
{
	// char *p;
	int k;
	setlocale(LC_ALL, "");
	//max -  18446744073709551615

	k = 0;

 	// ft_printf("[%#x]\n", 61);
 	// printf("%u\n", 4294967295);
 	printf("Le fichier {cyan}%s{eoc} contient : \e[32m!!!\e[0m\n", "hello");
 	printf("\e[35m%s\033[0m\033[31mmamasita\033[0m\033[36mboom\033[0m\033[33mboom\033[0m\033[34mboom\033[0m\n", "hello");

	// ft_printf("mine - [%*d]\n", NULL);
	// printf("orig - [%*d]\n", NULL);

	//    printf("orig - %hhd\n", 4294967295);
	// ft_printf("mine - %hhd\n", 4294967295);
	// ft_printf("mamasita %p hello %% again %X %C\n", p, 61, L'🎈');
	//    printf("mamasita %p hello %% again %X %C\n", p, 61, L'🎈');
	// ft_printf("%X %x %% %o %s %p\n", 61, 61, 61, "hello", &p);
	//    printf("%X %x %% %o %s %p\n", 61, 61, 61, "hello", &p);
	//    printf("%D %U %o %O\n", 8422, 61, 9223372036854775807, 9223372036854775807);
	// ft_printf("%D %U %o %O\n", 8422, 61, 9223372036854775807, 9223372036854775807);

	return (0);
}