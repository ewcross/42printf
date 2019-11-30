/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv2_ft_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:34:19 by ecross            #+#    #+#             */
/*   Updated: 2019/11/28 10:59:05 by elliotcro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*x_convert(va_list arg_list, t_list *list)
{
	int					i;
	int					prec;
	long long unsigned	arg;
	char				*var;

	prec = list->flag_vals[get_pos(list->flag_chars, '.')];
	arg = va_arg(arg_list, long long unsigned);
	if (arg == 0 && prec == 0
			&& list->flag_found[get_pos(list->flag_chars, '.')] == 1)
		return (malloc_empty_string());
	var = hex_convert(u_resize(arg, list), 87);
	i = 0;
	while (var[i])
		i++;
	if (prec > i)
		var = num_precision(var, prec, i - 1);
	if (arg && list->new_flag_found[get_pos(NEW_FLAGS, '#')])
		var = add_prefix(var, 'x');
	return (var);
}

char	*xx_convert(va_list arg_list, t_list *list)
{
	int					i;
	int					prec;
	long long unsigned	arg;
	char				*var;

	prec = list->flag_vals[get_pos(list->flag_chars, '.')];
	arg = va_arg(arg_list, long long unsigned);
	if (arg == 0 && prec == 0
			&& list->flag_found[get_pos(list->flag_chars, '.')] == 1)
		return (malloc_empty_string());
	var = hex_convert(u_resize(arg, list), 55);
	i = 0;
	while (var[i])
		i++;
	if (prec > i)
		var = num_precision(var, prec, i - 1);
	if (arg && list->new_flag_found[get_pos(NEW_FLAGS, '#')])
		var = add_prefix(var, 'X');
	return (var);
}

char	*f_convert(va_list arg_list, t_list *list)
{
	int			prec;
	double		arg;
	char		hash;
	char		commas;
	char		*var;

	hash = list->new_flag_found[get_pos(NEW_FLAGS, '#')];
	commas = list->new_flag_found[get_pos(NEW_FLAGS, '\'')];
	if (list->flag_found[get_pos(list->flag_chars, '.')])
	{
		prec = list->flag_vals[get_pos(list->flag_chars, '.')];
		if (prec < 0)
			prec = 6;
	}
	else
		prec = 6;
	arg = va_arg(arg_list, double);
	if (arg == INFINITY)
		return (ft_strdup("inf"));
	if (arg == -INFINITY)
		return (ft_strdup("-inf"));
	var = ftoa((double)arg, prec, hash, commas);
	if (var[0] != '-')
		var = prefix_signed(var, list);
	return (var);
}

char	*e_convert(va_list arg_list, t_list *list)
{
	int			prec;
	double		arg;
	char		hash;
	char		*exp;
	char		*var;

	hash = list->new_flag_found[get_pos(NEW_FLAGS, '#')];
	prec = 6;
	if (list->flag_found[get_pos(list->flag_chars, '.')])
	{
		prec = list->flag_vals[get_pos(list->flag_chars, '.')];
		if (prec < 0)
			prec = 6;
	}
	arg = va_arg(arg_list, double);
	if (arg == INFINITY)
		return (ft_strdup("inf"));
	if (arg == -INFINITY)
		return (ft_strdup("-inf"));
	exp = get_exponent(&arg);
	var = ftoa((double)arg, prec, hash, 0);
	var = reformat_e(var, exp);
	if (var[0] != '-')
		var = prefix_signed(var, list);
	return (var);
}

char	*n_convert(va_list arg_list, t_list *list)
{
	char	*var;
	void	*arg_ptr;

	arg_ptr = va_arg(arg_list, void *);
	if (list->h == 2)
		*((char *)arg_ptr) = (char)g_char_count;
	else if (list->h == 1)
		*((short *)arg_ptr) = (short)g_char_count;
	else if (list->l == 1)
		*((long *)arg_ptr) = (long)g_char_count;
	else if (list->l == 2)
		*((long long *)arg_ptr) = g_char_count;
	else
		*((int *)arg_ptr) = (int)g_char_count;
	if (!(var = (char*)malloc(1)))
		return (NULL);
	var[0] = 0;
	return (var);
}
