/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2ch19/11/14 12:54:47 by ecross            #+#    #+#             */
/*   Updated: 2019/11/18 16:23:45 by elliotcro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

int main(int c, char **v)
{
	long long li = -9223372036854775807;

	(void)c;
	/*ft_printf("...%.*f...\n", atoi(v[1]), f);
	printf("...%.*f...\n", atoi(v[1]), f);*/
	ft_printf("mine...%lld...\n", li);
	printf("real...%lld...\n", li);
	(void)v;
	return (0);
}
