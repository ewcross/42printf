/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:13:50 by ecross            #+#    #+#             */
/*   Updated: 2019/12/05 18:34:19 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *str, ...)
{
	t_list		*spec_list;
	va_list		arg_list;

	g_char_count = 0;
	spec_list = NULL;
	va_start(arg_list, str);
	if (make_list(str, &spec_list))
		if (!write_output(str, arg_list, spec_list))
			g_char_count = -1;
	free_list(&spec_list);
	va_end(arg_list);
	return (g_char_count);
}
