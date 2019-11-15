/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_processing_ft_printf.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:53:52 by ecross            #+#    #+#             */
/*   Updated: 2019/11/15 18:17:15 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	set_flag_value(t_list *elem, char flag, int value)
{
	int i;

	if (flag == '%')
		flag = 'r';
	i = 0;
	while (i < F_NUM)
	{
		if (elem->flag_chars[i] == flag)
			break ;
		i++;
	}
	elem->flag_vals[i] = value;
	elem->flag_found[i] = 1;
}

void	manage_flags(t_list *elem)
{
	int r;
	int zero;
	int dash;
	int dot;

	r = get_pos(elem->flag_chars, 'r');
	zero = get_pos(elem->flag_chars, '0');
	dash = get_pos(elem->flag_chars, '-');
	dot = get_pos(elem->flag_chars, '.');
	if (elem->flag_vals[dash])
	{
		elem->flag_vals[r] = 0;
		elem->flag_vals[zero] = 0;
	}
	if (is_in(elem->type, "diuxX"))
	{
		if (elem->flag_found[dot] && elem->flag_vals[zero])
		{
			elem->flag_vals[r] = elem->flag_vals[zero];
			elem->flag_vals[zero] = 0;
		}
	}
}

int		get_width(t_list *elem, const char *str, int i, char flag)
{
	int		width_start;

	if (str[i + 1] == '*')
	{
		if (i + 2 == elem->end_pos || is_in(str[i + 2], SPEC_DELIMS)
				|| is_in(str[i + 2], SIZE_CHARS))
		{
			set_flag_value(elem, flag, -1);
			i += 2;
		}
	}
	else
	{
		width_start = ++i;
		while (str[i] > 47 && str[i] < 58)
			i++;
		set_flag_value(elem, flag, flag_atoi(str, width_start, i));
	}
	return (i);
}

int		get_size_prefix(t_list *elem, const char *str, int i)
{
	if (str[i] == str[i + 1])
	{
		if (str[i] == 'h')
			elem->h = 2;
		if (str[i] == 'l')
			elem->l = 2;
		return (i + 2);
	}
	else
	{
		if (str[i] == 'h')
			elem->h = 1;
		if (str[i] == 'l')
			elem->l = 1;
		return (i + 1);
	}
}

void	set_format(const char *str, t_list *elem)
{
	int		i;
	int		end;
	char	flag;

	i = elem->start_pos;
	end = elem->end_pos;
	if (str[end] == 0)
		return ;
	while (i < end)
	{
		if (is_in(str[i], SPEC_DELIMS))
		{
			if (i == elem->start_pos && str[i + 1] == '0')
				flag = str[++i];
			else
				flag = str[i];
			i = get_width(elem, str, i, flag);
			if (is_in(str[i], SIZE_CHARS))
				i = get_size_prefix(elem, str, i);
		}
		else
			i++;
	}
	manage_flags(elem);
}
