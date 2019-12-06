/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_processing_ft_printf_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:28:47 by ecross            #+#    #+#             */
/*   Updated: 2019/12/06 11:40:21 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		put_wstr(wchar_t *w_str)
{
	int i;

	i = 0;
	while (w_str[i])
	{
		write(1, w_str + i, 1);
		g_char_count++;
		i++;
	}
}

void	wide_str_handling(va_list arg_list, t_list *list, int prec)
{
	wchar_t *w_null;

	w_null = L"(null)";
	list->w_str = va_arg(arg_list, wchar_t *);
	list->w_str = ft_strdup_wide(list->w_str);
	if (!list->w_str)
		list->w_str = ft_strdup_wide(w_null);
	if (list->flag_found[prec])
		list->w_str = str_prec_wide(list->w_str, list->flag_vals[prec]);
}

int		wstr_too_big(va_list arg_list, t_list *list)
{
	wchar_t	*w_str;
	va_list list_copy;

	if (list->l == 1 || list->l == 2)
	{
		va_copy(list_copy, arg_list);
		w_str = va_arg(list_copy, wchar_t *);
		va_end(list_copy);
		if (!w_str)
			return (0);
		while (*w_str)
		{
			if (*w_str > 255)
				return (1);
			w_str++;
		}
	}
	return (0);
}

int		wint_too_big(va_list arg_list, t_list *list)
{
	wint_t	w_int;
	va_list list_copy;

	if (list->l == 1 || list->l == 2)
	{
		va_copy(list_copy, arg_list);
		w_int = va_arg(list_copy, wint_t);
		va_end(list_copy);
		if (w_int > 255)
			return (1);
	}
	return (0);
}
