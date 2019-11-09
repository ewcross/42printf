/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_ft_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:59:55 by ecross            #+#    #+#             */
/*   Updated: 2019/11/09 12:54:01 by elliotcro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	check_stars(va_list arg_list, t_list *list)
{
	if (list->flag_vals[get_pos(list->flag_chars, 'r')] == -1)
		list->flag_vals[get_pos(list->flag_chars, 'r')] = va_arg(arg_list, int);
	else if (list->flag_vals[get_pos(list->flag_chars, '0')] == -1)
		list->flag_vals[get_pos(list->flag_chars, '0')] = va_arg(arg_list, int);
	else if (list->flag_vals[get_pos(list->flag_chars, '-')] == -1)
		list->flag_vals[get_pos(list->flag_chars, '-')] = va_arg(arg_list, int);
	if (list->flag_vals[get_pos(list->flag_chars, '.')] == -1)
		list->flag_vals[get_pos(list->flag_chars, '.')] = va_arg(arg_list, int);
}

void	write_padded(char *str, t_list *spec_list)
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
		pad(str, '0', zero);
	i = 0;
	while (str[i])
	{
		write(1, str + i, 1);
		i++;
	}
	if (!r && !zero)
	{
		l = spec_list->flag_vals[get_pos(spec_list->flag_chars, '-')];
		pad(str, ' ', l);
	}
}

int		write_spec(va_list arg_list, t_list *spec_list,
					char *(*f_ptr_arr[TYPE_NUM])(va_list, t_list *))
{
	int		type_index;
	char	*var;

	check_stars(arg_list, spec_list);
	if (!is_in(spec_list->type, TYPE_SET))
	{
		if (!(var = (char*)malloc(2)))
			return (1);
		var[0] = spec_list->type;
		var[1] = 0;
	}
	else
	{
		type_index = get_pos(TYPE_SET, spec_list->type);
		var = f_ptr_arr[type_index](arg_list, spec_list);
	}
	write_padded(var, spec_list);
	if (spec_list->type != 's')
		free(var);
	return (0);
}

int		write_output(const char *str, va_list arg_list, t_list *spec_list)
{
	int			i;
	const char	*ch_ptr;
	char		*(*f_ptr_arr[TYPE_NUM])(va_list, t_list *);

	init_f_ptr_arr(f_ptr_arr);
	ch_ptr = str;
	i = 0;
	while (spec_list)
	{
		while (ch_ptr < str + spec_list->start_pos)
			write(1, ch_ptr++, 1);
		if (spec_list->type == 0)
			return (1);
		write_spec(arg_list, spec_list, f_ptr_arr);
		while (ch_ptr < str + spec_list->end_pos + 1)
			ch_ptr++;
		spec_list = spec_list->next;
	}
	while (*ch_ptr)
		write(1, ch_ptr++, 1);
	return (0);
}
