/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:03:51 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 13:03:52 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

bool	init_ants(t_data *data)
{
	if (data->n_ants >= 0)
		return (false);
	data->n_ants = get_num(LINE, data);
	return (true);
}
