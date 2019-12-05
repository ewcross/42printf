/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv1_ft_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:47:51 by ecross            #+#    #+#             */
/*   Updated: 2019/12/05 19:42:28 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*c_convert(t_list *list, va_list arg_list)
{
	char	*var;

	var = (char*)malloc(2);
	if (!var)
		return (NULL);
	var[1] = 0;
	if (list->l == 1 || list->l == 2)
	{
		list->wide_char_found = 1;
		list->w_int = va_arg(arg_list, wint_t);
		var[0] = 0;
		if (list->w_int > 255)
			return (NULL);
		return (var);
	}
	var[0] = va_arg(arg_list, int);
	return (var);
}

char	*s_convert(t_list *list, va_list arg_list)
{
	int		prec_pos;
	char	*var;
	char	*null;

	null = "(null)";
	prec_pos = get_pos(list->flag_chars, '.');
	if (list->l == 1 || list->l == 2)
	{
		list->wide_str_found = 1;
		var = ft_strdup("h");
		wide_str_handling(arg_list, list)
	}
	else
	{
		var = va_arg(arg_list, char *);
		var = ft_strdup(var);
		if (!var)
			var = ft_strdup(null);
		if (list->flag_found[prec_pos])
			var = str_precision(var, list->flag_vals[prec_pos]);
	}
	return (var);
}

char	*p_convert(t_list *list, va_list arg_list)
{
	int				i;
	int				prec;
	unsigned long	addr;
	char			*var;

	(void)list;
	prec = list->flag_vals[get_pos(list->flag_chars, '.')];
	addr = (unsigned long)va_arg(arg_list, void *);
	if (addr == 0 && prec == 0
			&& list->flag_found[get_pos(list->flag_chars, '.')] == 1)
		return (add_prefix(malloc_empty_string(), 'x'));
	var = hex_convert(addr, 87);
	if (list->new_flag_found[get_pos(NEW_FLAGS, '\'')])
		var = add_commas(var);
	i = 0;
	while (var[i])
		i++;
	if (prec > i)
		var = num_precision(var, prec, i - 1);
	var = add_prefix(var, 'x');
	return (var);
}

char	*di_convert(t_list *list, va_list arg_list)
{
	int			i;
	int			prec;
	long long	arg;
	char		*var;

	prec = list->flag_vals[get_pos(list->flag_chars, '.')];
	arg = va_arg(arg_list, long long);
	if (arg == 0 && prec == 0
			&& list->flag_found[get_pos(list->flag_chars, '.')] == 1)
		return (prefix_signed(malloc_empty_string(), list));
	var = ft_itoa(resize(arg, list));
	if (list->new_flag_found[get_pos(NEW_FLAGS, '\'')])
		var = add_commas(var);
	i = 0;
	while (var[i])
		i++;
	if (prec > i - 1)
		var = num_precision(var, prec, i - 1);
	if (var[0] != '-')
		var = prefix_signed(var, list);
	return (var);
}

char	*u_convert(t_list *list, va_list arg_list)
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
	var = ft_u_itoa(u_resize(arg, list));
	if (list->new_flag_found[get_pos(NEW_FLAGS, '\'')])
		var = add_commas(var);
	i = 0;
	while (var[i])
		i++;
	if (prec > i)
		var = num_precision(var, prec, i - 1);
	return (var);
}
