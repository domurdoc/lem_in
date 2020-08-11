/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:04:02 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 14:41:37 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_flags(int ac, char **av, t_data *data)
{
	data->flags = 0;
	while (--ac)
	{
		if (ft_strequ(av[ac], "-h"))
			msg_help();
		else if (ft_strequ(av[ac], "-v"))
			data->flags |= VERBOSE;
		else if (ft_strequ(av[ac], "-t"))
			data->flags |= PATHS_NUM;
		else if (ft_strequ(av[ac], "-p"))
			data->flags |= SHOW_PATHS;
		else if (ft_strequ(av[ac], "-i"))
			data->flags |= IGNORE_LINKS;
		else if (ft_strequ(av[ac], "-g"))
			data->flags |= GRAPHICS;
		else if (ft_strequ(av[ac], "-r"))
			data->flags |= RANDOMIZE;
		else if (ft_strequ(av[ac], "-x"))
			data->flags |= OMMIT_INPUT;
		else if (ft_strequ(av[ac], "-xx"))
			data->flags |= OMMIT_ALL;
		else
			msg_usage();
	}
}
