/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv3_ft_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:33:31 by ecross            #+#    #+#             */
/*   Updated: 2019/11/25 16:24:02 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	get_x_p(double arg, int *x_p, t_list *list)
{
	char	*exp_str;

	exp_str = get_exponent(&arg);
	x_p[0] = flag_atoi(exp_str, 2, ft_strlen(exp_str));
	free(exp_str);
	exp_str = NULL;
	if (list->flag_found[get_pos(list->flag_chars, '.')])
	{
		x_p[1] = list->flag_vals[get_pos(list->flag_chars, '.')];
		if (x_p[1] < 0)
			x_p[1] = 1;
	}
	else
		x_p[1] = 6;
}

char	*trim_zeros(char *str)
{
	int		i;
	int		size;
	char	*new;

	i = 0;
	while (str[i])
		i++;
	size = i - 1;
	while (str[size] == '0')
		size--;
	if (str[size] == '.')
		size--;
	size++;
	if (!(new = (char*)malloc(size + 1)))
		return (NULL);
	new[size] = 0;
	i = -1;
	while (++i < size)
		new[i] = str[i];
	free(str);
	return (new);
}

int		g_inf_checker(double arg, char **var_addr)
{
	if (arg == INFINITY)
	{
		*var_addr = ft_strdup("inf");
		return (1);
	}
	if (arg == -INFINITY)
	{
		*var_addr = ft_strdup("-inf");
		return (1);
	}
	return (0);
}

char	*g_convert(va_list arg_list, t_list *list)
{
	int		x_p[2];
	double	arg;
	char	h_c[2];
	char	*exp_str;
	char	*var;

	h_c[0] = list->new_flag_found[get_pos(NEW_FLAGS, '#')];
	h_c[1] = list->new_flag_found[get_pos(NEW_FLAGS, '\'')];
	if (g_inf_checker((arg = va_arg(arg_list, double)), &var))
		return (var);
	get_x_p(arg, x_p, list);
	if (x_p[1] > x_p[0] && x_p[0] > -5)
	{
		var = ftoa((double)arg, x_p[1] - (x_p[0] + 1), h_c[0], h_c[1]);
		if (var[0] != '-')
			var = prefix_signed(var, list);
		if (!h_c[0])
			var = trim_zeros(var);
		return (var);
	}
	exp_str = get_exponent(&arg);
	var = ftoa((double)arg, x_p[1] - 1, h_c[0], 0);
	if (var[0] != '-')
		var = prefix_signed(var, list);
	return (ft_strjoin(var, exp_str));
}
