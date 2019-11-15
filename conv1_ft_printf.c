/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv1_ft_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:47:51 by ecross            #+#    #+#             */
/*   Updated: 2019/11/15 09:16:09 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*c_convert(va_list arg_list, t_list *list)
{
	char *var;

	(void)list;
	var = (char*)malloc(2);
	if (!var)
		return (NULL);
	var[0] = va_arg(arg_list, int);
	var[1] = 0;
	return (var);
}

char	*s_convert(va_list arg_list, t_list *list)
{
	int		prec_pos;
	char	*var;

	prec_pos = get_pos(list->flag_chars, '.');
	var = va_arg(arg_list, char *);
	if (!var)
		var = "(null)";
	if (list->flag_found[prec_pos])
		var = str_precision(var, list->flag_vals[prec_pos]);
	return (var);
}

char	*p_convert(va_list arg_list, t_list *list)
{
	unsigned long	addr;
	char			*var;

	(void)list;
	addr = (unsigned long long)va_arg(arg_list, void *);
	var = add_prefix(hex_convert(addr, 87));
	return (var);
}

char	*di_convert(va_list arg_list, t_list *list)
{
	int		i;
	int		prec;
	int		arg;
	char	*var;

	prec = list->flag_vals[get_pos(list->flag_chars, '.')];
	arg = va_arg(arg_list, int);
	if (arg == 0 && prec == 0
			&& list->flag_found[get_pos(list->flag_chars, '.')] == 1)
		return (malloc_empty_string());
	if (list->h == 2)
		var = ft_itoa((long long)((char)arg));
	else if (list->h == 1)
		var = ft_itoa((long long)((short)arg));
	else
		var = ft_itoa((long long)arg);
	i = 0;
	while (var[i])
		i++;
	if (prec > i)
		var = num_precision(var, prec, i);
	return (var);
}

char	*u_convert(va_list arg_list, t_list *list)
{
	int				i;
	int				prec;
	unsigned int	arg;
	char			*var;

	prec = list->flag_vals[get_pos(list->flag_chars, '.')];
	arg = va_arg(arg_list, unsigned int);
	if (arg == 0 && prec == 0
			&& list->flag_found[get_pos(list->flag_chars, '.')] == 1)
		return (malloc_empty_string());
	if (list->h == 2)
		var = ft_itoa((long long unsigned)((char unsigned)arg));
	else if (list->h == 1)
		var = ft_itoa((long long unsigned)((short unsigned)arg));
	else
		var = ft_u_itoa((long long unsigned)arg);
	i = 0;
	while (var[i])
		i++;
	if (prec > i)
		var = num_precision(var, prec, i);
	return (var);
}
