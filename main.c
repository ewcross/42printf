/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2ch19/11/14 12:54:47 by ecross            #+#    #+#             */
/*   Updated: 2019/11/15 18:44:14 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

int main(int c, char **v)
{
	char ch = '\0';
	int a = 12;
	
	(void)c;
	ft_printf("-->%d\n", ft_printf("%*c, %*c, %*c, %-*c, %-*c, %-*c, %.*c, %.*c, %.*c, %c", a, ch, -a, ch, a - 12, ch, a, ch, -a, ch, a - 12, ch, a, ch, -a, ch, a - 12, ch, ch));	
	printf("-->%d\n", printf("%*c, %*c, %*c, %-*c, %-*c, %-*c, %.*c, %.*c, %.*c, %c", a, ch, -a, ch, a - 12, ch, a, ch, -a, ch, a - 12, ch, a, ch, -a, ch, a - 12, ch, ch));
	return (0);
}
