#include "lem_in.h"

void	vis_data(t_data *data)
{
	reset_set(data);
	usleep(100000);
	mlx_clear_window(data->vis->mlx, data->vis->win);
	show_intro_2(data);
	mlx_key_hook(data->vis->win, keyboard_control, data);
	mlx_loop_hook(data->vis->mlx, vis_move, data);
	mlx_loop(data->vis->mlx);
}
