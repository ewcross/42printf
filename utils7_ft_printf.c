/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7_ft_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:28:49 by ecross            #+#    #+#             */
/*   Updated: 2019/12/04 18:10:34 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		float_specials(double arg, char **var_addr)
{
	int n;

	n = NAN;
	if (arg == INFINITY)
	{
		*var_addr = ft_strdup("inf");
		return (1);
	}
	else if (arg == -INFINITY)
	{
		*var_addr = ft_strdup("-inf");
		return (1);
	}
	else
		return (0);
}

