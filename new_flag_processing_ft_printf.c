/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_flag_processing_ft_printf.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elliotcross <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:37:35 by ecross            #+#    #+#             */
/*   Updated: 2019/11/19 16:55:31 by elliotcro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	get_new_flags(const char *str, t_list *elem)
{
	int i;
	int end;

	i = elem->start_pos;
	end = elem->end_pos;
	while (i < end)
	{
		if (is_in(str[i], NEW_FLAGS))
			elem->new_flag_found[get_pos(NEW_FLAGS, str[i])] = 1;
		i++;
	}
	if (elem->new_flag_found[get_pos(NEW_FLAGS, ' ')]
			&& elem->new_flag_found[get_pos(NEW_FLAGS, '+')])
		elem->new_flag_found[get_pos(NEW_FLAGS, ' ')] = 0;
	printf("space val is: %d\n", elem->new_flag_found[get_pos(NEW_FLAGS, ' ')]);
	printf("+ val is: %d\n", elem->new_flag_found[get_pos(NEW_FLAGS, '+')]);
	printf("# val is: %d\n", elem->new_flag_found[get_pos(NEW_FLAGS, '#')]);
}
