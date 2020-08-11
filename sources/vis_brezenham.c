/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_brezenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:38:30 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 13:38:30 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	init_fy(t_point *p1, t_point *p2, int d[4])
{
	if (p2->y < p1->y)
		ft_swap_p((void**)&p1, (void**)&p2);
	d[1] = p2->y - p1->y;
	d[2] = p2->x < p1->x ? -1 : 1;
	d[0] = d[2] * (p2->x - p1->x);
	d[3] = (d[0] << 1) - d[1];
	d[1] = (d[0] - d[1]) << 1;
	d[0] <<= 1;
}

static void	line_fy(t_point p1, t_point p2, int8_t **img)
{
	int		d[4];

	init_fy(&p1, &p2, d);
	while (p1.y <= p2.y)
	{
		img[p1.y][p1.x] = 1;
		if (d[3] < 0)
			d[3] += d[0];
		else
		{
			p1.x += d[2];
			d[3] += d[1];
		}
		p1.y++;
	}
}

static void	init_fx(t_point *p1, t_point *p2, int d[4])
{
	if (p2->x < p1->x)
		ft_swap_p((void**)&p1, (void**)&p2);
	d[1] = p2->x - p1->x;
	d[2] = p2->y < p1->y ? -1 : 1;
	d[0] = d[2] * (p2->y - p1->y);
	d[3] = (d[0] << 1) - d[1];
	d[1] = (d[0] - d[1]) << 1;
	d[0] <<= 1;
}

static void	line_fx(t_point p1, t_point p2, int8_t **img)
{
	int		d[4];

	init_fx(&p1, &p2, d);
	while (p1.x <= p2.x)
	{
		img[p1.y][p1.x] = 1;
		if (d[3] < 0)
			d[3] += d[0];
		else
		{
			p1.y += d[2];
			d[3] += d[1];
		}
		p1.x++;
	}
}

void		line_to_image(t_point p1, t_point p2, int8_t **img)
{
	if (abs(p2.x - p1.x) > abs(p2.y - p1.y))
		line_fx(p1, p2, img);
	else
		line_fy(p1, p2, img);
}
