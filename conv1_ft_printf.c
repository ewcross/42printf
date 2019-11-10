/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv1_ft_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:47:51 by ecross            #+#    #+#             */
/*   Updated: 2019/11/10 17:03:32 by elliotcro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*c_convert(va_list arg_list, t_list *list)
{
	char *var;

	var = (char*)malloc(2);
	if (!var)
		return (NULL);
	var[0] = va_arg(arg_list, int);
	var[1] = 0;
	return (var);
}

char	*s_convert(va_list arg_list, t_list *list)
{
	int		prec_pos;
	char	*var;

	prec_pos = get_pos(list->flag_chars, '.');
	var = va_arg(arg_list, char *);
	if (!var)
		var = "(null)";
	if (list->flag_found[prec_pos])
		var = str_precision(var, list->flag_vals[prec_pos]);
	return (var);
}

char	*p_convert(va_list arg_list, t_list *list)
{
	unsigned long	addr;
	char			*var;

	addr = (unsigned long)va_arg(arg_list, void *);
	var = add_prefix(hex_convert(addr, 87));
	return (var);
}

char	*di_convert(va_list arg_list, t_list *list)
{
	int		i;
	int		prec;
	char	*var;

	prec = list->flag_vals[get_pos(list->flag_chars, '.')];
	if (list->l == 1)
		var = ft_itoa(va_arg(arg_list, long int));
	if (list->l == 2)
		var = ft_itoa(va_arg(arg_list, long long int));
	else
		var = ft_itoa(va_arg(arg_list, int));
	i = 0;
	while (var[i])
		i++;
	if (prec > i)
		var = num_precision(var, prec, i);
	return (var);
}

char	*u_convert(va_list arg_list, t_list *list)
{
	int		i;
	int		prec;
	char	*var;

	prec = list->flag_vals[get_pos(list->flag_chars, '.')];
	if (list->l == 1)
		var = ft_u_itoa(va_arg(arg_list, long unsigned int));
	if (list->l == 2)
		var = ft_u_itoa(va_arg(arg_list, long long unsigned int));
	else
		var = ft_u_itoa(va_arg(arg_list, unsigned int));
	i = 0;
	while (var[i])
		i++;
	if (prec > i)
		var = num_precision(var, prec, i);
	return (var);
}

char	*x_convert(va_list arg_list, t_list *list)
{
	int		i;
	int		prec;
	char	*var;

	prec = list->flag_vals[get_pos(list->flag_chars, '.')];
	if (list->l == 1)
		var = hex_convert(va_arg(arg_list, long unsigned int), 87);
	if (list->l == 2)
		var = hex_convert(va_arg(arg_list, long long unsigned int), 87);
	else
		var = hex_convert(va_arg(arg_list, unsigned int), 87);
	i = 0;
	while (var[i])
		i++;
	if (prec > i)
		var = num_precision(var, prec, i);
	return (var);
}

char	*xx_convert(va_list arg_list, t_list *list)
{
	int		i;
	int		prec;
	char	*var;

	prec = list->flag_vals[get_pos(list->flag_chars, '.')];
	if (list->l == 1)
		var = hex_convert(va_arg(arg_list, long unsigned int), 55);
	if (list->l == 2)
		var = hex_convert(va_arg(arg_list, long long unsigned int), 55);
	else
		var = hex_convert(va_arg(arg_list, unsigned int), 55);
	i = 0;
	while (var[i])
		i++;
	if (prec > i)
		var = num_precision(var, prec, i);
	return (var);
}
