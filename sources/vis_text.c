/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:38:55 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 15:54:50 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	show_info(t_data *data)
{
	char	*str;

	mlx_string_put(data->vis->mlx, data->vis->win, 10, 20, MENU_COLOR,
		"ANTS total - ");
	str = data->buff_line;
	nbr_recursion(data->n_ants, &str);
	*str = '\0';
	mlx_string_put(data->vis->mlx, data->vis->win, 95, 20, MENU_COLOR,
		data->buff_line);
	mlx_string_put(data->vis->mlx, data->vis->win, 150, 20, MENU_COLOR,
		"ANTS finished - ");
	str = data->buff_line;
	nbr_recursion(data->vis->n, &str);
	*str = '\0';
	mlx_string_put(data->vis->mlx, data->vis->win, 250, 20, MENU_COLOR,
		data->buff_line);
	mlx_string_put(data->vis->mlx, data->vis->win, 450, 20, MENU_COLOR,
		"ROOMS - ");
	str = data->buff_line;
	nbr_recursion(data->rooms->len, &str);
	*str = '\0';
	mlx_string_put(data->vis->mlx, data->vis->win, 500, 20, MENU_COLOR,
		data->buff_line);
}

void	show_menu(t_data *data)
{
	mlx_string_put(data->vis->mlx, data->vis->win, 460, 755, MENU_COLOR,
		"<space> play/pause");
	mlx_string_put(data->vis->mlx, data->vis->win, 10, 755, MENU_COLOR,
		"<esc> exit");
	mlx_string_put(data->vis->mlx, data->vis->win, 933, 755, MENU_COLOR,
		"<rshift> rooms");
	mlx_string_put(data->vis->mlx, data->vis->win, 902, 20, MENU_COLOR,
		"<backspace> restart");
}

void	show_intro_1(t_data *data)
{
	mlx_string_put(data->vis->mlx, data->vis->win, 480, 350, MENU_COLOR,
		"LOADING...");
}

void	show_intro_2(t_data *data)
{
	mlx_string_put(data->vis->mlx, data->vis->win, 465, 350, MENU_COLOR,
		"<space> to start");
	mlx_string_put(data->vis->mlx, data->vis->win, 473, 370, MENU_COLOR,
		"<esc> to exit");
}

void	show_rooms(t_data *data)
{
	mlx_string_put(data->vis->mlx, data->vis->win, 600, 20, MENU_COLOR,
		"RED dst     BLUE src");
}
