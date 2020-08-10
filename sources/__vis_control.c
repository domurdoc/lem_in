#include "lem_in.h"

static void	control_exit(int key, t_data *data)
{
	if (key == 53)
		exit_(OK, data);
}

static void	control_pause(int key, t_data *data)
{
	if (key == 49)
		data->vis->paused = !data->vis->paused;
}

static void	control_reset(int key, t_data *data)
{
	if (key == 51)
		reset_set(data);
}

static void	control_rooms(int key, t_data *data)
{
	if (key == 258)
		data->vis->show_rooms = !data->vis->show_rooms;
}

int			keyboard_control(int key, t_data *data)
{
	control_exit(key, data);
	control_pause(key, data);
	control_reset(key, data);
	control_rooms(key, data);
	return (0);
}
