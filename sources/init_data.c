/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:04:00 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 13:22:28 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_data(t_data *data)
{
	init_prepare(data);
	init_line_process(data, init_ants);
	init_ants_check(data);
	init_line_process(data, init_rooms);
	init_rooms_check(data);
	init_line_process(data, init_links);
	init_simple_check(data);
	if (data->flags & GRAPHICS)
		vis_prepare(data);
}
