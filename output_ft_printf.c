/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_ft_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:59:55 by ecross            #+#    #+#             */
/*   Updated: 2019/11/15 09:47:34 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		check_stars(va_list arg_list, t_list *list)
{
	int r_pos;
	int zero_pos;
	int dash_pos;
	int dot_pos;

	r_pos = get_pos(list->flag_chars, 'r');
	zero_pos = get_pos(list->flag_chars, '0');
	dash_pos = get_pos(list->flag_chars, '-');
	dot_pos = get_pos(list->flag_chars, '.');
	if (list->flag_vals[r_pos] == -1)
		list->flag_vals[r_pos] = va_arg(arg_list, int);
	else if (list->flag_vals[zero_pos] == -1)
		list->flag_vals[zero_pos] = va_arg(arg_list, int);
	else if (list->flag_vals[dash_pos] == -1)
		list->flag_vals[dash_pos] = va_arg(arg_list, int);
	negs(r_pos, zero_pos, dash_pos, list);
	if (list->flag_vals[dot_pos] == -1)
		list->flag_vals[dot_pos] = va_arg(arg_list, int);
}

void		write_padded(char *str, t_list *spec_list)
{
	int	i;
	int r;
	int zero;
	int l;

	r = spec_list->flag_vals[get_pos(spec_list->flag_chars, 'r')];
	zero = spec_list->flag_vals[get_pos(spec_list->flag_chars, '0')];
	if (!str)
		return ;
	if (r)
		pad(str, ' ', r);
	else if (zero)
		str = pad(str, '0', zero);
	i = 0;
	while (str[i])
	{
		write(1, str + i, 1);
		g_char_count++;
		i++;
	}
	if (!r && !zero)
	{
		l = spec_list->flag_vals[get_pos(spec_list->flag_chars, '-')];
		pad(str, ' ', l);
	}
}

int			write_spec(va_list arg_list, t_list *spec_list,
					char *(*f_ptr_arr[TYPE_NUM])(va_list, t_list *))
{
	int		type_index;
	char	*var;

	check_stars(arg_list, spec_list);
	if (!is_in(spec_list->type, TYPE_SET))
	{
		if (!(var = (char*)malloc(2)))
			return (0);
		var[0] = spec_list->type;
		var[1] = 0;
	}
	else
	{
		type_index = get_pos(TYPE_SET, spec_list->type);
		if (!(var = f_ptr_arr[type_index](arg_list, spec_list)))
			return (0);
	}
	write_padded(var, spec_list);
	if (spec_list->type != 's')
		free(var);
	return (1);
}

const char	*write_plaintext(const char *ch_ptr)
{
	if (*ch_ptr == '%')
		ch_ptr++;
	write(1, ch_ptr++, 1);
	g_char_count++;
	return (ch_ptr);
}

int			write_output(const char *str, va_list arg_list, t_list *spec_list)
{
	const char	*ch_ptr;
	char		*(*f_ptr_arr[TYPE_NUM])(va_list, t_list *);

	init_f_ptr_arr(f_ptr_arr);
	ch_ptr = str;
	while (spec_list)
	{
		while (ch_ptr < str + spec_list->start_pos)
			ch_ptr = write_plaintext(ch_ptr);
		if (spec_list->type == 0)
			return (1);
		if (!write_spec(arg_list, spec_list, f_ptr_arr))
			return (0);
		while (ch_ptr < str + spec_list->end_pos + 1)
			ch_ptr++;
		spec_list = spec_list->next;
	}
	while (*ch_ptr)
		ch_ptr = write_plaintext(ch_ptr);
	return (1);
}
