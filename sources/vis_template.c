/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_template.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:38:52 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 13:38:52 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	flood_fill(int x, int y, int8_t **img)
{
	img[x][y] = 1;
	if (!img[x + 1][y])
		flood_fill(x + 1, y, img);
	if (!img[x - 1][y])
		flood_fill(x - 1, y, img);
	if (!img[x][y + 1])
		flood_fill(x, y + 1, img);
	if (!img[x][y - 1])
		flood_fill(x, y - 1, img);
}

static void	circle_to_img(int r, int x0, int y0, int8_t **img)
{
	int x;
	int	y;
	int d;
	int e;

	x = 0;
	y = r;
	d = 1 - 2 * r;
	e = 0;
	while (y >= 0)
	{
		img[x0 + x][y0 + y] = 1;
		img[x0 + x][y0 - y] = 1;
		img[x0 - x][y0 + y] = 1;
		img[x0 - x][y0 - y] = 1;
		e = ((d + y) << 1) - 1;
		if (d < 0 && e <= 0)
			d += (++x << 1) + 1;
		else if (d > 0 && e > 0)
			d -= (--y << 1) + 1;
		else
			d += (++x - --y) << 1;
	}
}

void		draw_template(t_data *data)
{
	circle_to_img((data->vis->img_size - 3) / 2, data->vis->img_hsize,
		data->vis->img_hsize, data->vis->img_ant);
	flood_fill(data->vis->img_hsize, data->vis->img_hsize, data->vis->img_ant);
}
