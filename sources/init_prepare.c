/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prepare.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:04:07 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 13:25:08 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	prepare_rooms(t_data *data)
{
	if (!(data->rooms = ar_new(DEFAULT_R, room_del)))
		exit_(MEMORY_ERROR, data);
	data->rooms->cmp = cmp_names;
	room_add(data);
}

static void	prepare_input(t_data *data)
{
	if (!(data->input = lst_ht_new()))
		exit_(MEMORY_ERROR, data);
}

void		init_prepare(t_data *data)
{
	prepare_rooms(data);
	prepare_input(data);
	data->n_ants = -1;
	data->start_room = NULL;
	data->end_room = NULL;
	data->best_set = NULL;
	data->curr_set = NULL;
	data->prev_set = NULL;
	data->words = NULL;
	data->error_r = 0;
	data->i_buff = 0;
	data->heap = NULL;
	data->vis = NULL;
}
