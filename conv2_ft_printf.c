/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv2_ft_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:06:38 by ecross            #+#    #+#             */
/*   Updated: 2019/11/07 16:37:37 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*x_convert(va_list arg_list, int prec)
{
	int		i;
	char	*var;

	var = hex_convert(va_arg(arg_list, unsigned int), 87);
	i = 0;
	while (var[i])
		i++;
	if (prec > i)
		var = num_precision(var, prec, i);
	return (var);
}

char	*xx_convert(va_list arg_list, int prec)
{
	int		i;
	char	*var;

	var = hex_convert(va_arg(arg_list, unsigned int), 55);
	i = 0;
	while (var[i])
		i++;
	if (prec > i)
		var = num_precision(var, prec, i);
	return (var);
}
