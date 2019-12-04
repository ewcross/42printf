/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_flag_ft_printf_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:16:12 by ecross            #+#    #+#             */
/*   Updated: 2019/12/04 18:16:13 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	get_x_p(double arg, int *x_p, t_list *list)
{
	char	*exp_str;

	exp_str = get_exponent(&arg);
	x_p[0] = pos_atoi(exp_str, 1);
	free(exp_str);
	if (list->flag_found[get_pos(list->flag_chars, '.')])
	{
		x_p[1] = list->flag_vals[get_pos(list->flag_chars, '.')];
		if (x_p[1] < 1)
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

int		dots(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

char	*make_f(double arg, int *x_p, char *h_c, t_list *list)
{
	char	*var;

	var = ftoa((double)arg, x_p[1] - (x_p[0] + 1), h_c[0], h_c[1]);
	if (var[0] != '-')
		var = prefix_signed(var, list);
	if (!h_c[0])
		var = trim_zeros(var);
	return (var);
}
