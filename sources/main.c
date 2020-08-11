/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:04:23 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 13:04:23 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(int ac, char **av)
{
	t_data data;

	init_flags(ac, av, &data);
	init_data(&data);
	process_data(&data);
	output_data(&data);
	exit_(OK, &data);
}
