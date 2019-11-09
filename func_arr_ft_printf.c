/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_arr_ft_printf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:04:02 by ecross            #+#    #+#             */
/*   Updated: 2019/11/09 12:52:02 by elliotcro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
}
