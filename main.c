/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:54:47 by ecross            #+#    #+#             */
/*   Updated: 2019/11/15 09:44:52 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

int main(int c, char **v)
{
	(void)c;

	ft_printf("-->%d\n", ft_printf("...%0*d...", atoi(v[1]), -5));
	printf("-->%d\n", printf("...%0*d...", atoi(v[1]), -5));
	return (0);
}
