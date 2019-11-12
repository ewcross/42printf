/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:13:50 by ecross            #+#    #+#             */
/*   Updated: 2019/11/12 11:08:37 by elliotcro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *str, ...)
{
	t_list		*spec_list;
	va_list		arg_list;

	spec_list = NULL;
	va_start(arg_list, str);
	make_list(str, &spec_list);
	write_output(str, arg_list, spec_list);
	write(1, "\n", 1);
	free_list(&spec_list);
	va_end(arg_list);
	return (0);
}

int	main(int c, char **v)
{
	if (c < 2)
	{
		printf("one arg please\n");
		return (1);
	}
	ft_printf(v[1], 123456789);
	return (0);
}
