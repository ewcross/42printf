/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_flag_processing_ft_printf.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elliotcross <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:37:35 by ecross            #+#    #+#             */
/*   Updated: 2019/11/22 12:06:01 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*prefix_signed(char *num, t_list *list)
{
	int		i;
	char	pref;
	char	*new;

	if (list->new_flag_found[get_pos(NEW_FLAGS, '+')])
		pref = '+';
	else if (list->new_flag_found[get_pos(NEW_FLAGS, ' ')])
		pref = ' ';
	else
		return (num);
	i = 0;
	while (num[i])
		i++;
	if (!(new = (char*)malloc(i + 2)))
		return (NULL);
	new[i + 1] = 0;
	new[0] = pref;
	i = -1;
	while (num[++i])
		new[i + 1] = num[i];
	free(num);
	return (new);
}

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
}
