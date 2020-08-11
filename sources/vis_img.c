#include "lem_in.h"

void	put_img_ant(t_ant *ant, t_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = ant->coord.x - data->vis->img_hsize;
	y = ant->coord.y - data->vis->img_hsize;
	j = -1;
	while (++j < data->vis->img_size)
	{
		i = -1;
		while (++i < data->vis->img_size)
			if (data->vis->img_ant[j][i])
				data->vis->img_data[y + j][x + i] = ant->color;
	}
}

void	put_img_tunnels(t_data *data)
{
	int	i;
	int	j;

	j = -1;
	while (++j < IMG_H)
	{
		i = -1;
		while (++i < IMG_W)
			if (data->vis->img_tunnels[j][i])
				data->vis->img_data[j][i] = LINE_COLOR;
			else
				data->vis->img_data[j][i] = BACKGROUND;
	}
}

void	clear_img(int8_t **img, int w, int h)
{
	int	i;
	int	j;

	j = -1;
	while (++j < h)
	{
		i = -1;
		while (++i < w)
			img[j][i] = 0;
	}
}
