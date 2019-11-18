/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4_ft_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:36:34 by ecross            #+#    #+#             */
/*   Updated: 2019/11/18 15:45:39 by elliotcro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
			&& !list->flag_found[r_pos] && list->type != 'c')
	{
		list->flag_vals[zero_pos] = list->flag_vals[r_pos];
		list->flag_vals[r_pos] = 0;
	}
}

void	init_f_ptr_arr(char *(*f_ptr_arr[])(va_list, t_list *))
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
	f_ptr_arr[get_pos(TYPE_SET, 'n')] = n_convert;
}
