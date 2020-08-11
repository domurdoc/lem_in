/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_usage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:04:42 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 13:04:42 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	msg_usage(void)
{
	char	*msg;

	msg = "lem-in: undefined combination\ntry 'lem-in -h' for more information";
	ft_dprintf(STDERR_FILENO, "%s\n", msg);
	exit(1);
}
