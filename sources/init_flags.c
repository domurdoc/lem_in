/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:04:02 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 13:04:02 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_flags(int ac, char **av, t_data *data)
{
	int	i;

	i = 0;
	data->flags = 0;
	while (++i < ac)
	{
		if (ft_strequ(av[i], "-h"))
			msg_help();
		else if (ft_strequ(av[i], "-v"))
			data->flags |= VERBOSE;
		else if (ft_strequ(av[i], "-t"))
			data->flags |= PATHS_NUM;
		else if (ft_strequ(av[i], "-p"))
			data->flags |= SHOW_PATHS;
		else if (ft_strequ(av[i], "-i"))
			data->flags |= IGNORE_LINKS;
		else if (ft_strequ(av[i], "-g"))
			data->flags |= GRAPHICS;
		else if (ft_strequ(av[i], "-r"))
			data->flags |= RANDOMIZE;
		else
			msg_usage();
	}
}
