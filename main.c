/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2ch19/11/14 12:54:47 by ecross            #+#    #+#             */
/*   Updated: 2019/11/19 17:00:06 by elliotcro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

int main(int c, char **v)
{
	int i = 5;

	(void)c;
	ft_printf("...%+d...\n", i);
	ft_printf("...% d...\n", i);
	ft_printf("...%+ d...\n", i);
	ft_printf("...% +d...\n", i);
	ft_printf("...%#d...\n", i);
	ft_printf("...%+#d...\n", i);
	ft_printf("...% #d...\n", i);
	(void)v;
	return (0);
}
