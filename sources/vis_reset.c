/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_reset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:38:47 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 13:38:47 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	reset_set(t_data *data)
{
	uint32_t	i;

	i = 0;
	while (i < data->best_set->paths->len)
	{
		((t_path*)data->best_set->paths->data[i])->n_s_ants = 0;
		((t_path*)data->best_set->paths->data[i])->n_f_ants = 0;
		i++;
	}
	data->vis->n = 0;
}
