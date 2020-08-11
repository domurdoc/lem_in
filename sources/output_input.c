/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:04:51 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 13:04:51 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	output_input(t_data *data)
{
	char	*line;

	while ((line = lst_ht_pop(data->input)))
	{
		buff_fill(line, data);
		buff_fill("\n", data);
		free(line);
	}
	buff_fill("\n", data);
	buff_flush(data);
	ft_memdel((void**)&data->input);
}
