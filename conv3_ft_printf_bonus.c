/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv3_ft_printf_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:12:17 by ecross            #+#    #+#             */
/*   Updated: 2019/12/04 19:01:22 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*f_convert(t_list *list, va_list arg_list)
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
	if (!float_specials(arg, &var))
		var = ftoa((double)arg, prec, hash, commas);
	if (var[0] != '-')
		var = prefix_signed(var, list);
	return (var);
}

char	*e_convert(t_list *list, va_list arg_list)
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
	if (!float_specials(arg, &var))
	{
		exp = get_exponent(&arg);
		var = ftoa((double)arg, prec, hash, 0);
		var = reformat_e(var, exp);
	}
	if (var[0] != '-')
		var = prefix_signed(var, list);
	return (var);
}

char	*g_convert(t_list *list, va_list arg_list)
{
	int		x_p[2];
	double	arg;
	char	h_c[2];
	char	*exp_str;
	char	*var;

	h_c[0] = list->new_flag_found[get_pos(NEW_FLAGS, '#')];
	h_c[1] = list->new_flag_found[get_pos(NEW_FLAGS, '\'')];
	if (g_inf_checker((arg = va_arg(arg_list, double)), &var))
		return (var);
	get_x_p(arg, x_p, list);
	if ((x_p[1] > x_p[0] && x_p[0] > -5) || (x_p[0] == 0 && x_p[1] == 0))
		return (make_f(arg, x_p, h_c, list));
	exp_str = get_exponent(&arg);
	var = ftoa((double)arg, x_p[1] - 1, h_c[0], 0);
	if (!h_c[0] && dots(var))
		var = trim_zeros(var);
	var = reformat_e(var, exp_str);
	if (var[0] != '-')
		var = prefix_signed(var, list);
	return (var);
}

char	*n_convert(t_list *list, va_list arg_list)
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
