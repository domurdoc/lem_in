/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:38:49 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 13:38:50 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	square_to_img(int x, int y, int **img, int color)
{
	int i;
	int j;

	x -= ROOM_SIZE / 2;
	y -= ROOM_SIZE / 2;
	j = -1;
	while (++j < ROOM_SIZE)
	{
		i = -1;
		while (++i < ROOM_SIZE)
			img[y + j][x + i] = color;
	}
}

void		put_img_rooms(t_data *data)
{
	square_to_img(data->start_room->coord.x, data->start_room->coord.y,
		data->vis->img_data, SROOM_COLOR);
	square_to_img(data->end_room->coord.x, data->end_room->coord.y,
		data->vis->img_data, EROOM_COLOR);
}
