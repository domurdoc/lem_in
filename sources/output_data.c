/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:04:46 by domurdoc          #+#    #+#             */
/*   Updated: 2020/12/27 01:27:55 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	output_data(t_data *data)
{
    if (!(data->flags & OMMIT_ALL) || data->flags & SHOW_PATHS)
    {
        output_prepare(data);
    }
    if (!(data->flags & OMMIT_ALL))
	{
		if (!(data->flags & OMMIT_INPUT))
			output_input(data);
		while (output_line(data))
			;
	}
	if (data->flags & SHOW_PATHS)
		show_paths(data);
	if (data->flags & PATHS_NUM)
		show_total(data);
}
