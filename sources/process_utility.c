/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:05:24 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 13:05:24 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int32_t	min_iter(t_data *data)
{
	double	x;
	int32_t	y;

	x = (double)data->prev_set->length / data->prev_set->paths->len
		+ data->n_ants_average;
	y = (int32_t)x;
	return (y < x ? y + 1 : y);
}

void	backtrack(t_data *data, void (*func)(t_node*, t_data*))
{
	uint32_t	i;

	if (!data->prev_set)
		return ;
	i = 0;
	while (i < data->prev_set->paths->len)
	{
		(*func)(((t_lst_ht*)data->prev_set->paths->data[i])->tail->data,
			data);
		i++;
	}
}
