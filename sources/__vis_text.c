#include "lem_in.h"

void	show_info(t_data *data)
{
	char	*str;

	mlx_string_put(data->vis->mlx, data->vis->win, 10, 10, MENU_COLOR,
		"ANTS total - ");
	str = data->buff_line;
	nbr_recursion(data->n_ants, &str);
	*str = '\0';
	mlx_string_put(data->vis->mlx, data->vis->win, 150, 10, MENU_COLOR,
		data->buff_line);
	mlx_string_put(data->vis->mlx, data->vis->win, 250, 10, MENU_COLOR,
		"ANTS finished - ");
	str = data->buff_line;
	nbr_recursion(data->vis->n, &str);
	*str = '\0';
	mlx_string_put(data->vis->mlx, data->vis->win, 425, 10, MENU_COLOR,
		data->buff_line);
}

void	show_menu(t_data *data)
{
	mlx_string_put(data->vis->mlx, data->vis->win, 870, 1050, MENU_COLOR,
		"<space> play/pause");
	mlx_string_put(data->vis->mlx, data->vis->win, 10, 1050, MENU_COLOR,
		"<esc> exit");
	mlx_string_put(data->vis->mlx, data->vis->win, 1767, 1050, MENU_COLOR,
		"<rshift> rooms");
	mlx_string_put(data->vis->mlx, data->vis->win, 1720, 10, MENU_COLOR,
		"<backspace> restart");
}

void	show_intro_1(t_data *data)
{
	mlx_string_put(data->vis->mlx, data->vis->win, 880, 500, MENU_COLOR,
		"LOADING...");
}

void	show_intro_2(t_data *data)
{
	mlx_string_put(data->vis->mlx, data->vis->win, 880, 500, MENU_COLOR,
		"<space> to start");
	mlx_string_put(data->vis->mlx, data->vis->win, 893, 530, MENU_COLOR,
		"<esc> to exit");
}

void	show_rooms(t_data *data)
{
	mlx_string_put(data->vis->mlx, data->vis->win, 1000, 10, MENU_COLOR,
		"RED dst     BLUE src");
}
