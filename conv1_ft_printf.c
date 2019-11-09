/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv1_ft_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:47:51 by ecross            #+#    #+#             */
/*   Updated: 2019/11/07 16:39:22 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*c_convert(va_list arg_list, int prec)
{
	char *var;

	prec = 0;
	var = (char*)malloc(2);
	if (!var)
		return (NULL);
	var[0] = va_arg(arg_list, int);
	var[1] = 0;
	return (var);
}

char	*s_convert(va_list arg_list, int prec)
{
	char	*var;

	var = va_arg(arg_list, char *);
	if (!var)
		var = "(null)";
	else if (prec > -1)
		var = str_precision(var, prec);
	return (var);
}

char	*p_convert(va_list arg_list, int prec)
{
	unsigned long	addr;
	char			*var;

	prec = 0;
	addr = (unsigned long)va_arg(arg_list, void *);
	var = add_prefix(hex_convert(addr, 87));
	return (var);
}

char	*di_convert(va_list arg_list, int prec)
{
	int		i;
	char	*var;

	var = ft_itoa(va_arg(arg_list, int));
	i = 0;
	while (var[i])
		i++;
	if (prec > i)
		var = num_precision(var, prec, i);
	return (var);
}

char	*u_convert(va_list arg_list, int prec)
{
	int		i;
	char	*var;

	var = ft_u_itoa(va_arg(arg_list, unsigned int));
	i = 0;
	while (var[i])
		i++;
	if (prec > i)
		var = num_precision(var, prec, i);
	return (var);
}
