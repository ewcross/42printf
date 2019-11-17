/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elliotcross <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 21:40:39 by elliotcro         #+#    #+#             */
/*   Updated: 2019/11/17 22:37:08 by elliotcro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_printf(float f, int prec)
{
	int i;
	int to_print;

	i = 0;
	f = f - (int)f;
	write(1, "          ", 11);
	while (i < prec)
	{
		f = f * 10;
		to_print = (int)f;
		f = f - (int)f;
		if (i == prec - 1 && (int)(f * 10) > 4)
			to_print += 1;
		to_print += 48;
		write(1, &to_print, 1);
		i++;
	}
	printf("\n");
}

int main(int c, char **v)
{
	float f;

	(void)c;
	f = 123.456789;
	printf("real: %.*f\n", atoi(v[1]), f);
	ft_printf(f, atoi(v[1]));
}
