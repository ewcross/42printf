/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2ch19/11/14 12:54:47 by ecross            #+#    #+#             */
/*   Updated: 2019/11/18 16:14:00 by elliotcro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

int main(int c, char **v)
{
	int i;

	i = 0;
	(void)c;
	/*ft_printf("...%.*f...\n", atoi(v[1]), f);
	printf("...%.*f...\n", atoi(v[1]), f);*/
	printf("%d\n", i);
	ft_printf("mine...%n...%d...\n", &i, i);
	ft_printf("mine...%n...%d...\n", &i, i);
	printf("real...%n...%d...\n", &i, i);
	printf("real...%n...%d...\n", &i, i);
	(void)v;
	return (0);
}
