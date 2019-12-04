/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4_ft_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:36:34 by ecross            #+#    #+#             */
/*   Updated: 2019/12/04 18:54:46 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*copy(char *str)
{
	int		i;
	char	*new;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
		i++;
	if (!(new = (char*)malloc(i + 1)))
		return (NULL);
	new[i] = 0;
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	return (new);
}

void	negs(int r_pos, int zero_pos, int dash_pos, t_list *list)
{
	if (list->flag_vals[r_pos] < 0)
	{
		list->flag_vals[dash_pos] = (list->flag_vals[r_pos] * -1);
		list->flag_vals[r_pos] = 0;
	}
	else if (list->flag_vals[zero_pos] < 0)
	{
		list->flag_vals[dash_pos] = (list->flag_vals[zero_pos] * -1);
		list->flag_vals[zero_pos] = 0;
	}
	else if (list->flag_vals[dash_pos] < 0)
		list->flag_vals[dash_pos] *= -1;
	if (list->flag_vals[get_pos(list->flag_chars, '.')] < 0
			&& !list->flag_found[r_pos] && list->type != 'c'
			&& list->type != 'f')
	{
		list->flag_vals[zero_pos] = list->flag_vals[r_pos];
		list->flag_vals[r_pos] = 0;
	}
}

void	init_f_ptr_arr(char *(*f_ptr_arr[])(t_list *, va_list))
{
	f_ptr_arr[get_pos(TYPE_SET, 'c')] = c_convert;
	f_ptr_arr[get_pos(TYPE_SET, 's')] = s_convert;
	f_ptr_arr[get_pos(TYPE_SET, 'p')] = p_convert;
	f_ptr_arr[get_pos(TYPE_SET, 'd')] = di_convert;
	f_ptr_arr[get_pos(TYPE_SET, 'i')] = di_convert;
	f_ptr_arr[get_pos(TYPE_SET, 'u')] = u_convert;
	f_ptr_arr[get_pos(TYPE_SET, 'x')] = x_convert;
	f_ptr_arr[get_pos(TYPE_SET, 'X')] = xx_convert;
	f_ptr_arr[get_pos(TYPE_SET, 'f')] = f_convert;
	f_ptr_arr[get_pos(TYPE_SET, 'e')] = e_convert;
	f_ptr_arr[get_pos(TYPE_SET, 'g')] = g_convert;
	f_ptr_arr[get_pos(TYPE_SET, 'n')] = n_convert;
}

void	check_stars(va_list arg_list, t_list *list)
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
	if (list->flag_vals[dot_pos] == -1)
		list->flag_vals[dot_pos] = va_arg(arg_list, int);
	negs(r_pos, zero_pos, dash_pos, list);
}
