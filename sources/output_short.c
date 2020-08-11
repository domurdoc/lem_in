/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_short.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:04:58 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 13:05:03 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	output_short(t_data *data)
{
	int64_t	i;
	char	buff_name[16];

	i = 0;
	while (++i <= data->n_ants)
	{
		ant_name(i, buff_name);
		buff_fill(buff_name, data);
		buff_fill(data->end_room->name, data);
		buff_fill(" ", data);
	}
	data->buff_line[data->i_buff - 1] = '\n';
	buff_flush(data);
}
