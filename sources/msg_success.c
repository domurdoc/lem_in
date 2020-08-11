/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_success.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:04:40 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 13:04:40 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	msg_success(t_data *data)
{
	if (data->best_set)
		ft_dprintf(STDOUT_FILENO, "%{5}finished in %d turn%s%{0}\n",
			data->best_set->iter, data->best_set->iter > 1 ? "s" : "");
	else if (data->n_ants > 0)
		ft_dprintf(STDOUT_FILENO, "%{5}finished in 1 turn%{0}\n");
	else
		ft_dprintf(STDOUT_FILENO, "%{5}finished in 0 turns%{0}\n");
}
