/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:04:46 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 13:24:04 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	output_data(t_data *data)
{
	output_prepare(data);
	output_input(data);
	while (output_line(data))
		;
	if (data->flags & SHOW_PATHS)
		show_paths(data);
	if (data->flags & PATHS_NUM)
		show_total(data);
	if (data->flags & GRAPHICS)
		vis_data(data);
}
