/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_tunnels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:38:57 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 13:38:57 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	max_min_coord(t_data *data, t_point *max, t_point *min)
{
	uint32_t	i;

	i = 0;
	max->x = 0;
	max->y = 0;
	min->x = INT_MAX;
	min->y = INT_MAX;
	while (i < N_ROOMS)
	{
		if (ROOM(i)->coord.x > max->x)
			max->x = ROOM(i)->coord.x;
		if (ROOM(i)->coord.x < min->x)
			min->x = ROOM(i)->coord.x;
		if (ROOM(i)->coord.y > max->y)
			max->y = ROOM(i)->coord.y;
		if (ROOM(i)->coord.y < min->y)
			min->y = ROOM(i)->coord.y;
		i++;
	}
}

static void	adjust_rooms(t_data *data, t_dpoint scale, t_point min)
{
	uint32_t	i;

	i = 0;
	while (i < N_ROOMS)
	{
		ROOM(i)->coord.x =
			(double)(ROOM(i)->coord.x - min.x) / scale.x + IMG_HB;
		ROOM(i)->coord.y =
			(double)(ROOM(i)->coord.y - min.y) / scale.y + IMG_VB;
		i++;
	}
}

static int	dist_app(t_point p1, t_point p2)
{
	int	dx;
	int	dy;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	return (dx * dx + dy * dy);
}

static void	brute_force(t_data *data)
{
	uint32_t	i;
	uint32_t	j;
	t_node		*curr;
	t_node		*next;
	int			d;

	i = 0;
	while (i < N_ROOMS)
	{
		curr = ROOM(i)->origin;
		j = 0;
		while (j < curr->links->len)
		{
			next = ((t_link*)curr->links->data[j])->n;
			if ((d = dist_app(curr->r->coord, next->r->coord)) < data->vis->d)
				data->vis->d = d;
			line_to_image(curr->r->coord, next->r->coord,
				data->vis->img_tunnels);
			j++;
		}
		i++;
	}
}

void		draw_tunnels(t_data *data)
{
	t_point		max;
	t_point		min;
	t_dpoint	scale;

	max_min_coord(data, &max, &min);
	scale.x = (double)(max.x - min.x) / (IMG_W - 2 * IMG_HB);
	scale.y = (double)(max.y - min.y) / (IMG_H - 2 * IMG_VB);
	if (!scale.x)
		scale.x = 1;
	if (!scale.y)
		scale.y = 1;
	adjust_rooms(data, scale, min);
	brute_force(data);
}
