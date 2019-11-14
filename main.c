/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:54:47 by ecross            #+#    #+#             */
/*   Updated: 2019/11/14 14:15:55 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

int main(int c, char **v)
{
	(void)c;
	int a = atoi(v[1]);
	int i = 5;

	ft_printf("right:\n");
	ft_printf("-->%d\n", ft_printf("...%*i...", a, i));
	printf("-->%d\n", printf("...%*i...", a, i));
	
	ft_printf("zero:\n");
	ft_printf("-->%d\n", ft_printf("...%0*i...", a, i));
	printf("-->%d\n", printf("...%0*i...", a, i));

	ft_printf("dash:\n");
	ft_printf("-->%d\n", ft_printf("...%-*i...", a, i));
	printf("-->%d\n", printf("...%-*i...", a, i));
	return (0);
}
