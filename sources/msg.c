/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:04:25 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 13:04:26 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	msg(int status, t_data *data)
{
	if (status)
		msg_error(status, data);
	else if (data->flags & VERBOSE)
		msg_success(data);
}
