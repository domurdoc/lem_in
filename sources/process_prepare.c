/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_prepare.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:05:17 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 13:05:17 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	prepare_heap(t_data *data)
{
	if (!(data->heap = ar_new(data->rooms->cap, NULL)))
		exit_(MEMORY_ERROR, data);
	data->heap->cmp = cmp_dist;
}

static void	prepare_best_set(t_data *data)
{
	if (!(data->best_set = set_new()))
		exit_(MEMORY_ERROR, data);
	data->best_set->iter = INT32_MAX;
}

static void	prepare_links(t_data *data)
{
	uint32_t	i;

	i = 0;
	while (i < N_ROOMS)
	{
		ar_quicksort(ROOM(i)->origin->links);
		i++;
	}
}

void		process_prepare(t_data *data)
{
	prepare_links(data);
	prepare_heap(data);
	prepare_best_set(data);
	data->n_ants_average = (double)data->n_ants
		/ ft_min(START->origin->links->len, END->origin->links->len);
}
