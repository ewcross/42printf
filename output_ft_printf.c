/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_ft_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:59:55 by ecross            #+#    #+#             */
/*   Updated: 2019/12/06 11:25:01 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		write_var(char *str, t_list *spec_list)
{
	int i;

	i = 0;
	if (spec_list->type == 'c' && spec_list->wide_char_found)
	{
		write(1, &(spec_list->w_int), 1);
		g_char_count++;
	}
	else if (spec_list->type == 'c' && str[0] == 0)
	{
		write(1, "\0", 1);
		g_char_count++;
	}
	else if (spec_list->type == 's' && spec_list->wide_str_found)
		put_wstr(spec_list->w_str);
	else
	{
		while (str[i])
		{
			write(1, str + i, 1);
			g_char_count++;
			i++;
		}
	}
}

void		write_padded(char *str, t_list *spec_list)
{
	int r;
	int zero;
	int l;

	r = spec_list->flag_vals[get_pos(spec_list->flag_chars, 'r')];
	zero = spec_list->flag_vals[get_pos(spec_list->flag_chars, '0')];
	if (!str)
		return ;
	if (r)
		pad(str, ' ', r, spec_list->type);
	else if (zero)
		str = pad(str, '0', zero, spec_list->type);
	write_var(str, spec_list);
	if (!r && !zero)
	{
		l = spec_list->flag_vals[get_pos(spec_list->flag_chars, '-')];
		pad(str, ' ', l, spec_list->type);
	}
}

int			write_spec(va_list arg_list, t_list *spec_list,
					char *(*f_ptr_arr[TYPE_NUM])(t_list *, va_list))
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
		if (!(var = f_ptr_arr[type_index](spec_list, arg_list)))
			return (0);
	}
	if (spec_list->type != 'n')
		write_padded(var, spec_list);
	if (spec_list->type == 's' && spec_list->wide_str_found)
		free(spec_list->w_str);
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
	char		*(*f_ptr_arr[TYPE_NUM])(t_list *, va_list);

	init_f_ptr_arr(f_ptr_arr);
	ch_ptr = str;
	while (spec_list)
	{
		if (spec_list->type == 'c' && wint_too_big(arg_list, spec_list))
			return (0);
		if (spec_list->type == 's' && wstr_too_big(arg_list, spec_list))
			return (0);
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
