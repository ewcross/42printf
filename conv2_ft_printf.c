/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv2_ft_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:34:19 by ecross            #+#    #+#             */
/*   Updated: 2019/11/15 16:22:52 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*x_convert(va_list arg_list, t_list *list)
{
	int				i;
	int				prec;
	unsigned int	arg;
	char			*var;

	prec = list->flag_vals[get_pos(list->flag_chars, '.')];
	arg = va_arg(arg_list, unsigned int);
	if (arg == 0 && prec == 0
			&& list->flag_found[get_pos(list->flag_chars, '.')] == 1)
		return (malloc_empty_string());
	if (list->h == 2)
		var = hex_convert((long long unsigned)((char unsigned)arg), 87);
	else if (list->h == 1)
		var = hex_convert((long long unsigned)((short unsigned)arg), 87);
	else
		var = hex_convert((long long unsigned)arg, 87);
	i = 0;
	while (var[i])
		i++;
	if (prec > i)
		var = num_precision(var, prec, i - 1);
	return (var);
}

char	*xx_convert(va_list arg_list, t_list *list)
{
	int				i;
	int				prec;
	unsigned int	arg;
	char			*var;

	prec = list->flag_vals[get_pos(list->flag_chars, '.')];
	arg = va_arg(arg_list, unsigned int);
	if (arg == 0 && prec == 0
			&& list->flag_found[get_pos(list->flag_chars, '.')] == 1)
		return (malloc_empty_string());
	if (list->h == 2)
		var = hex_convert((long long unsigned)((char unsigned)arg), 55);
	else if (list->h == 1)
		var = hex_convert((long long unsigned)((short unsigned)arg), 55);
	else
		var = hex_convert((long long unsigned)arg, 55);
	i = 0;
	while (var[i])
		i++;
	if (prec > i)
		var = num_precision(var, prec, i - 1);
	return (var);
}
