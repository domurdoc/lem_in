#include "lem_in.h"

static void	prepare_mlx(t_data *data, char *name)
{
	int	i;

	i = 0;
	if (!(data->vis->mlx = mlx_init()))
		exit_(MLX_ERROR, data);
	if (!(data->vis->win = mlx_new_window(data->vis->mlx, IMG_W, IMG_H, name)))
		exit_(MLX_ERROR, data);
	if (!(data->vis->img = mlx_new_image(data->vis->mlx, IMG_W, IMG_H)))
		exit_(MLX_ERROR, data);
	if (!(data->vis->img_data = (int**)malloc(sizeof(int*) * IMG_H)))
		exit_(MEMORY_ERROR, data);
	if (!(data->vis->img_data[0] = (int*)mlx_get_data_addr(data->vis->img,
		&data->vis->bpp, &data->vis->line_size, &data->vis->endian)))
		exit_(MLX_ERROR, data);
	while (++i < IMG_H)
		data->vis->img_data[i] = &(data->vis->img_data[0][i * IMG_W]);
}

static void	prepare_img_tunnels(t_data *data)
{
	int	i;

	if (!(data->vis->img_tunnels = (int8_t**)malloc(sizeof(int8_t*) * IMG_H)))
		exit_(MEMORY_ERROR, data);
	if (!(data->vis->img_tunnels[0] =
							(int8_t*)malloc(sizeof(int8_t) * IMG_H * IMG_W)))
		exit_(MEMORY_ERROR, data);
	i = 0;
	while (++i < IMG_H)
		data->vis->img_tunnels[i] = &data->vis->img_tunnels[0][i * IMG_W];
	clear_img(data->vis->img_tunnels, IMG_W, IMG_H);
}

static void	prepare_img_ant(t_data *data)
{
	int	r;
	int	i;

	r = (int)(sqrt((double)data->vis->d) / 100);
	if (r < 3)
		r = 3;
	else if (r > 10)
		r = 10;
	data->vis->img_size = r * 2 + 3;
	data->vis->img_hsize = data->vis->img_size / 2 + 1;
	if (!(data->vis->img_ant = (int8_t**)malloc(sizeof(int8_t*)
		* data->vis->img_size)))
		exit_(MEMORY_ERROR, data);
	if (!(data->vis->img_ant[0] = (int8_t*)malloc(sizeof(int8_t)
		* data->vis->img_size * data->vis->img_size)))
		exit_(MEMORY_ERROR, data);
	i = 0;
	while (++i < data->vis->img_size)
		data->vis->img_ant[i] = &data->vis->img_ant[0][i * data->vis->img_size];
	clear_img(data->vis->img_ant, data->vis->img_size, data->vis->img_size);
}

void		vis_prepare(t_data *data)
{
	if (!(data->vis = (t_vis*)malloc(sizeof(t_vis))))
		exit_(MEMORY_ERROR, data);
	data->vis->n = 0;
	data->vis->mlx = NULL;
	data->vis->win = NULL;
	data->vis->img = NULL;
	data->vis->img_data = NULL;
	data->vis->img_tunnels = NULL;
	data->vis->d = IMG_W * IMG_W + IMG_H * IMG_H;
	data->vis->paused = true;
	data->vis->show_rooms = true;
	prepare_mlx(data, "lem-in by domurdoc");
	show_intro_1(data);
	if (data->flags & RANDOMIZE)
		room_rand(data);
	prepare_img_tunnels(data);
	prepare_img_ant(data);
	draw_tunnels(data);
	draw_template(data);
}
