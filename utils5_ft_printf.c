/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5_ft_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:02:43 by ecross            #+#    #+#             */
/*   Updated: 2019/11/18 19:03:15 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long long			resize(long long arg, t_list *list)
{
	if (list->h == 2)
		return ((long long)((char)arg));
	else if (list->h == 1)
		return ((long long)((short)arg));
	else if (list->l == 1)
		return ((long long)((long)arg));
	else if (list->l == 2)
		return (arg);
	else
		return ((long long)(int)arg);
}

long long unsigned	u_resize(long long unsigned arg, t_list *list)
{
	if (list->h == 2)
		return ((long long unsigned)((char unsigned)arg));
	else if (list->h == 1)
		return ((long long unsigned)((short unsigned)arg));
	else if (list->l == 1)
		return ((long long unsigned)((long unsigned)arg));
	else if (list->l == 2)
		return (arg);
	else
		return ((long long unsigned)(int unsigned)arg);
}
