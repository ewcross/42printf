/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2ch19/11/14 12:54:47 by ecross            #+#    #+#             */
/*   Updated: 2019/11/18 19:15:56 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

int main(int c, char **v)
{
	double d = 123.12993456789;
	char *str = "sohalfkasdfasdf";

	(void)c;
	ft_printf("mine:...%.*s...\n", atoi(v[1]), str);
	printf("real:...%.*s...\n", atoi(v[1]), str);
	/*ft_printf("mine:...%*.*f...\n", atoi(v[1]), atoi(v[2]), d);
	printf("real:...%*.*f...\n", atoi(v[1]), atoi(v[2]), d);*/
	(void)v;
	return (0);
}
