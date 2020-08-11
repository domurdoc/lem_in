/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_utility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:38:59 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 13:39:00 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "time.h"

void	vis_del(t_vis *vis)
{
	if (vis)
	{
		if (vis->img_data)
			free(vis->img_data);
		if (vis->mlx && vis->img)
			mlx_destroy_image(vis->mlx, vis->img);
		if (vis->mlx && vis->win)
			mlx_destroy_window(vis->mlx, vis->win);
		free(vis->mlx);
		if (vis->img_ant && vis->img_ant[0])
			free(vis->img_ant[0]);
		free(vis->img_ant);
		if (vis->img_tunnels && vis->img_tunnels[0])
			free(vis->img_tunnels[0]);
		free(vis->img_tunnels);
		free(vis);
	}
}

void	flush(t_data *data)
{
	mlx_do_sync(data->vis->mlx);
	mlx_put_image_to_window(data->vis->mlx, data->vis->win, data->vis->img,
		0, 0);
	show_menu(data);
	show_info(data);
	if (data->vis->show_rooms)
		show_rooms(data);
}

void	room_rand(t_data *data)
{
	uint32_t	i;

	srand(time(NULL));
	i = 0;
	while (i < N_ROOMS)
	{
		ROOM(i)->coord.x = rand();
		ROOM(i)->coord.y = rand();
		i++;
	}
}
