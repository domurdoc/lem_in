/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simple_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:04:16 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 14:24:20 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_simple_check(t_data *data)
{
	if (!data->n_ants)
	{
		if (!(data->flags & OMMIT_ALL))
			if (!(data->flags & OMMIT_INPUT))
				output_input(data);
		if (data->flags & PATHS_NUM)
			show_total_0();
		exit_(OK, data);
	}
	else if (link_exists(START, END))
	{
		if (!(data->flags & OMMIT_ALL))
		{
			if (!(data->flags & OMMIT_INPUT))
				output_input(data);
			output_short(data);
		}
		if (data->flags & PATHS_NUM)
			show_total_1(data);
		exit_(OK, data);
	}
}
