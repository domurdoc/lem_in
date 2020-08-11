/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:38:41 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 13:38:42 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	get_delta(t_room *r1, t_room *r2, t_ant *ant)
{
	ant->coord.x = r1->coord.x;
	ant->coord.y = r1->coord.y;
	ant->delta.x = (double)(r2->coord.x - r1->coord.x) / STEPS;
	ant->delta.y = (double)(r2->coord.y - r1->coord.y) / STEPS;
}

static void	move_path(t_path *p, t_data *data)
{
	int32_t	i;

	p->i_ant = p->n_f_ants;
	i = p->n_f_ants;
	while (i < p->n_s_ants)
	{
		get_delta(p->rooms[p->ants[i].r],
			p->rooms[p->ants[i].r + 1], &p->ants[i]);
		if (++p->ants[i++].r == p->n_rooms)
		{
			p->n_f_ants++;
			data->vis->n++;
		}
	}
	if (p->n_s_ants < p->n_ants)
	{
		get_delta(data->start_room, p->rooms[0],
			&p->ants[p->n_s_ants]);
		p->ants[p->n_s_ants].color = rand() % 0xFFFFFF;
		p->ants[p->n_s_ants++].r = 0;
	}
}

static void	move_set(t_data *data)
{
	uint32_t	i;

	i = 0;
	while (i < data->best_set->paths->len)
		move_path(data->best_set->paths->data[i++], data);
}

static void	get_move(t_path *p, t_data *data)
{
	int32_t	i;

	i = p->i_ant;
	while (i < p->n_s_ants)
	{
		put_img_ant(&p->ants[i], data);
		p->ants[i].coord.x += p->ants[i].delta.x;
		p->ants[i].coord.y += p->ants[i].delta.y;
		i++;
	}
}

int			vis_move(t_data *data)
{
	int32_t		i;
	uint32_t	j;

	if (data->vis->n >= data->n_ants || data->vis->paused)
		return (0);
	usleep(500000);
	i = -2;
	move_set(data);
	flush(data);
	while (++i < STEPS)
	{
		usleep(50000);
		put_img_tunnels(data);
		if (data->vis->show_rooms)
			put_img_rooms(data);
		j = 0;
		while (j < data->best_set->paths->len)
			get_move(data->best_set->paths->data[j++], data);
		flush(data);
	}
	return (0);
}
